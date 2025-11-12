#include<bits/stdc++.h>
#define ll long long
const int N=1e5+5;
using namespace std;
int a[N][5];
int cun[N][5];
int n;
struct adj{
	int id,w;
}a1[N],a2[N];//第几组相差较大 
bool cmp1(adj q1,adj q2)
{
//	if(q1.w==q2.w)
	return q1.w>q2.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ll W=0;
		int w1[5];
		memset(w1,0,sizeof w1);
		int pan[N];
		memset(pan,0,sizeof pan);//看是否用过 
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			a1[i].id=i;a2[i].id=i;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3])
			{
				cun[i][1]=1;
				cun[i][2]=2;
				cun[i][3]=3;
				a1[i].w=a[i][1]-a[i][2];
				a2[i].w=a[i][2]-a[i][3];
			}
			else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2])
			{
				cun[i][1]=1;
				cun[i][2]=3;
				cun[i][3]=2;
				a1[i].w=a[i][1]-a[i][3];
				a2[i].w=a[i][3]-a[i][2];
			}
			else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])
			{
				cun[i][1]=2;
				cun[i][2]=1;
				cun[i][3]=3;
				a1[i].w=a[i][2]-a[i][1];
				a2[i].w=a[i][1]-a[i][3];
			}
			else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1])
			{
				cun[i][1]=2;
				cun[i][2]=3;
				cun[i][3]=1;
				a1[i].w=a[i][2]-a[i][3];
				a2[i].w=a[i][3]-a[i][1];
			}
			else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2])
			{
				cun[i][1]=3;
				cun[i][2]=1;
				cun[i][3]=2;
				a1[i].w=a[i][3]-a[i][1];
				a2[i].w=a[i][1]-a[i][2];
			}
			else if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1])
			{
				cun[i][1]=3;
				cun[i][2]=2;
				cun[i][3]=1;
				a1[i].w=a[i][3]-a[i][2];
				a2[i].w=a[i][2]-a[i][1];
			}
		}
//		比较第一组 
		sort(a1+1,a1+1+n,cmp1); 
//		for(int i=1;i<=n;i++)
//		{
//			cout<<a1[i].id<<" ";
//		}
//		puts(" ");
		for(int i=1;i<=n;i++)
		{
			if(w1[cun[a1[i].id][1]]<n/2)
			{
				w1[cun[a1[i].id][1]]++;
				W+=a[a1[i].id][cun[a1[i].id][1]];
				pan[a1[i].id]=1;
//				cout<<a1[i].id<<" "<<cun[a1[i].id][1]<<endl;
			}
		}
		if(w1[1]+w1[2]+w1[3]==n)
		{
			cout<<W<<endl;
			continue;
		}
		
//		比较第二组 
		for(int i=1;i<=n;i++)
		{
			if(pan[a2[i].id]==1)continue;
			if(w1[cun[a2[i].id][2]]<n/2)
			{
				w1[cun[a2[i].id][2]]++;
				W+=a[a2[i].id][cun[a2[i].id][2]];
				pan[a2[i].id]=1;
//				cout<<a2[i].id<<" "<<cun[a2[i].id][2]<<endl;
			}
		}
//		for(int i=1;i<=3;i++)
//			cout<<w1[i]<<" ";
//		for(int i=1;i<=n;i++)cout<<pan[i]<<" ";
//		puts(" "); 
		cout<<W<<endl;
	}
}
