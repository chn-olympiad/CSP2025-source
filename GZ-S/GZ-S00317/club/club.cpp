//GZ-S00317 贵阳中天中学 王巍然 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
int t;
int check,p1,p2,p3,sum=0;
int so[N],num=0;
struct node{
	int a,b,c;
}sa[N];
struct maxsatisfied{
	int cnt;
}ms[N];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	check=t/2;
	for(int i=1;i<=t;i++)
	{
		p1=0,p2=0,p3=0;
		int n; cin>>n;
		//int so[n+50];
		for(int j=1;j<=n;j++)
		{
			
			cin>>sa[j].a>>sa[j].b>>sa[j].c;
			//so[++num]=sa[j].a,so[num+2]=sa[j].b,so[num+3]=sa[j].c;
			//sort(so+1,so+n+1);
			ms[j].cnt=max(max(sa[j].a,sa[j].b),sa[j].c);
			if(p1<=check&&p2<=check&&p3<=check){
				if(ms[j].cnt==sa[j].a&&p1+1<=check) p1++,sum+=ms[j].cnt;
				else ms[j].cnt==sa[j].b&&p2+1<=check?p2++,sum+=ms[j].cnt:p3++,sum+=ms[j].cnt;
			}
		}
		cout<<sum<<endl;	
	}
	return 0;
}
