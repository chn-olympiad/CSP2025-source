#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000000],f=0,ans=0;
char o;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=998244353;
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	cin>>o;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		f++;
	}
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	cout<<ans<<endl;
	return 0;
} 
