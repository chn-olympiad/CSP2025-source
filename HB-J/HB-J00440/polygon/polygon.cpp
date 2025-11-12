#include <bits/stdc++.h>
using namespace std;

int stick[5001],n;
long long ans;

void solve(int num,int sum,int len,int selfp,int start)
{
	if(len>2 && sum>num)ans++;
	for(int i=start;i<=n;i++)
	{
		if(i!=selfp && stick[i]<=num)solve(num,sum+stick[i],len+1,selfp,i+1);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>stick[i];
	}
	if(n==3)
	{
		if(stick[1]+stick[2]>stick[3] && stick[1]+stick[3]>stick[2] && stick[3]+stick[2]>stick[1])
		{
			cout<<1;
		}
		else cout<<0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			solve(stick[i],0,1,i,1);
		}
	}
	if(ans<998244353)cout<<ans;
	else cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
