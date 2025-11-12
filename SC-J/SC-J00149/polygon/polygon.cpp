#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
bool s[5005];
void zhao(int k,int sum,int step,int maxx,int start)
{
	if(k==step)//回 
	{
		if(sum>2*maxx)
		{
			ans++;
		}
		return;
	}
	for(int i = start;i<=n;++i)//起点 
	{
		if(!s[i])//未选 
		{
			s[i]=1;
			zhao(k,sum+a[i],step+1,max(maxx,a[i]),start+1);
			s[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i = 3;i<=n;++i)//从三开始枚举 
	{
		memset(s,0,sizeof(s));
		zhao(i,0,1,-1e9,1);
	}
	cout<<(ans-3)/3;
	return 0;
}
