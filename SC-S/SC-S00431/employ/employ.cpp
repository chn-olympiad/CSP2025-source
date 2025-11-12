#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	
	long long n,m,ans=1;
	cin>>n>>m;
	string s;
	int a[505]={};
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(n==1)
			ans*=i;
		else if(s[i]=='1')
			ans++;
		else if(s[i]=='0')
			a[i+1]=a[i+2];

	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}