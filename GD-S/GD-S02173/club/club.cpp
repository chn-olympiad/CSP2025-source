#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m3,t,m2,m1,f1[N],f2[N],f3[N],h[N],ans=0;
struct node{
	int a1,a2,a3;
};
node a[N];
bool cmp(int n1,int n2)
{
	return a[n1].a1-max(a[n1].a2,a[n1].a3)>a[n2].a1-max(a[n2].a2,a[n2].a3);
}
bool cmp2(int n1,int n2)
{
	return a[n1].a2-max(a[n1].a1,a[n1].a3)>a[n2].a2-max(a[n2].a1,a[n2].a3);
}
bool cmp3(int n1,int n2)
{
	return a[n1].a3-max(a[n1].a2,a[n1].a1)>a[n2].a3-max(a[n2].a2,a[n2].a1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		ans=0,m1=0,m2=0,m3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			int p=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(p==a[i].a1){
				f1[++m1]=i;
				h[i]=1;
			}else if(p==a[i].a2){
				f2[++m2]=i;
				h[i]=2;
			}else{
				f3[++m3]=i;
				h[i]=3;
			}
		}
		if(m1*2>n)
		{
			sort(f1+1,f1+1+m1,cmp);
			for(int j=n/2+1;j<=m1;j++)
			{
				int i=f1[j];
				int p=max(a[i].a2,a[i].a3);
				if(p==a[i].a2)
				 h[i]=2;
				else
				 h[i]=3;
			}
		}else if(m2*2>n)
		{
			sort(f2+1,f2+1+m2,cmp2);
			for(int j=n/2+1;j<=m2;j++)
			{
				int i=f2[j];
				int p=max(a[i].a1,a[i].a3);
				if(p==a[i].a1)
				 h[i]=1;
				else
				 h[i]=3;
			}
		}else if(m3*2>n){
			sort(f3+1,f3+1+m3,cmp3);
			for(int j=n/2+1;j<=m3;j++)
			{
				int i=f3[j];
				int p=max(a[i].a2,a[i].a1);
				if(p==a[i].a2)
				 h[i]=2;
				else
				 h[i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(h[i]==1)
			 ans+=a[i].a1;
			else if(h[i]==2)
			 ans+=a[i].a2;
			else ans+=a[i].a3;
		}
		cout<<ans<<endl;
	}
	
	return 0;
 } 
