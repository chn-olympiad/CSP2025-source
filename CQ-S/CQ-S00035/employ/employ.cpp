#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,k,arr[100001],f=0,num=0,pre[100001];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(num>=arr[i])num++;
	}
	for(auto ne:s)if(ne!=1)f=1;
	pre[0]=1;
	for(int i=1;i<=501;i++)pre[i]=(pre[i-1]*i)%mod;
	cout<<pre[n-num];
	
	return 0;
}
