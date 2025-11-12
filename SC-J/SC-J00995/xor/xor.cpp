#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+1;
ll n,k,ans;
ll a[N],sum[N],num[N];
bool flag_A,flag_B;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	if(k!=0)flag_A=1;
	if(k>1)flag_B=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		num[sum[i]]++;
		if(flag_A==0&&a[i]!=1)flag_A=1;
		if(flag_B==0&&a[i]>1)flag_B=1;
	}	
	if(flag_A==0)
	{
		cout<<n/2<<endl;
		return 0;
	}
	if(flag_B==0)
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1&&a[i]==a[i+1])
					ans++,i+=2;
				else if(a[i]==0)ans++;
			}
		}
		else if(k==1)
		{
			for(int i=1;i<=n;i++)
				if(a[i]==1)ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	num[0]++;
	for(int i=n;i>=1;)
	{
		ll v=(k|sum[i]);
		if(sum[i]==k)v=0;
		sum[i]--;
		if(num[v]==0)
		{
			i--;
			continue;
		}
		if(num[v]>0)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(sum[j]==v)
				{
					ans++;
					i=j;
					break;
				}
				num[sum[j]]--;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2 
2 1 0 3
*/