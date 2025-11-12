#include<bits/stdc++.h>
#define N 505
#define mod 998244353
using namespace std;
string str;
int n,k;
int a[N];
int main()
{
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	cin>>str;
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='0')
		{
			flag=true;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(flag)
	{
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	int m=1;
	while(a[m]==0)
		++m;
//	cout<<n<<" "<<m<<"\n";
	long long ans=1;
	for(int i=1;i<=k;i++)
	{
		if(n-m+1-i+1<=0) break;
		ans*=(n-m+1-i+1);
		ans%=mod;
	}
	cout<<ans;
	return 0;
 } 