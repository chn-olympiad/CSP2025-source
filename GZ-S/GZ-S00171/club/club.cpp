//GZ-S00171 毕节七星关东辰实验学校 张碧昊 
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm> 
using namespace std;
typedef long long ll;
struct node
{
	ll n1;
	ll n2;
	ll n3;
}a[123456];

ll ans=-99999;
ll num[4];
ll n;

void dfs(ll x,ll val)
{
	ans=max(ans,val);
	if(x>n)return ;

	if(num[1]<n/2)
	{
		num[1]++;
		dfs(x+1,val+a[x].n1);
		num[1]--;
	}
	 if(num[2]<n/2)
	{
		num[2]++;
		dfs(x+1,val+a[x].n2);
		num[2]--;
	}
	 if(num[3]<n/2)
	{
		num[3]++;
		dfs(x+1,val+a[x].n3);
		num[3]--;
	}
	return ;
}
bool cmp1(node a,node b)
{
	return a.n1>b.n1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{

		num[1]=0;
		num[2]=0;
		num[3]=0;
		ans=-999999;
		cin>>n;

		ll qwq1=0;
		ll qwq2=0;
		for(int i=1;i<=n;i++)
		{

			cin>>a[i].n1>>a[i].n2>>a[i].n3;
			if(a[i].n2!=0)qwq1=1;
			if(a[i].n3!=0)qwq2=1;
		}

		if(qwq1==0&&qwq2==0)
		{
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].n1;
			}
			cout<<ans<<endl;
			
		}
		else
		{
			dfs(1,0);
		    cout<<ans<<endl;
		}
		
	} 
	
	
	return 0;
}

