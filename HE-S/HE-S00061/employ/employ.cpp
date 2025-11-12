#include<bits/stdc++.h>
using namespace std;
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long cnt=1,sum=1,ans=1;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=n;i>=1;i--)
		cnt*=i;
	for(int i=n-m;i>=1;i--)
		sum*=i;
	for(int i=m;i>=1;i--)
		ans*=i;
	cnt/=(sum*ans);
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
