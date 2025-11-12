#include<bits/stdc++.h>
using namespace std;
int n,a[5001],k[5001];
long long ans=0;

void stk(int sum,int maxx,int num,int flag)
{
	if(sum>maxx*2&&num>=3)
	{
		ans+=1;
		ans%=998244353;
	}
	for(int i=flag;i<n;i++)
		stk(sum+a[i],max(maxx,a[i]),num+1,i+1);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	stk(0,0,1,0);
	cout<<ans;
	return 0;
}
