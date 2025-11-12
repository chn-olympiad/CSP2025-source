#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int ANS=0,t,n,a[maxn],b[maxn],c[maxn];
void dfs(int now,int sum1,int sum2,int sum3,int cnt1,int cnt2,int cnt3)
{
//	cout<<"miku";
	if(now==n+1)
	{
		ANS=max(ANS,sum1+sum2+sum3);
		return;
	}
	if(cnt1<n/2)
	{
		dfs(now+1,sum1+a[now],sum2,sum3,cnt1+1,cnt2,cnt3);
	}
	if(cnt2<n/2)
	{
		dfs(now+1,sum1,sum2+b[now],sum3,cnt1,cnt2+1,cnt3);
	}
	if(cnt3<n/2)
	{
		dfs(now+1,sum1,sum2,sum3+c[now],cnt1,cnt2,cnt3+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ANS=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1,0,0,0,0,0,0);
		cout<<ANS<<endl;
	} 
	return 0;
}