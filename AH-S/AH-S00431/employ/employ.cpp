#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
unsigned long long ans=1;
int a[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
			cnt++;
		if(a[i]<=cnt)
			cnt++;
	}
	for(int i=n-m+cnt;i<=n;i++)
		ans*=i;
	if(n-m+cnt>=m)
		cout<<ans%998244353;
	else
		cout<<0;
	return 0;
}
//20zzc
//BLCQJ,DBCSY,SNOIYCK,BK long long JZZ,SSNNOI,SSNCSP,MQMJQ!
