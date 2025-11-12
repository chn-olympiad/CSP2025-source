#include<bits/stdc++.h>
using namespace std;
int a[5005];
const long long mod=998244353;
unsigned long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;	
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	bool f=0;
	for(int i=0;i<s.size();i++)
	{
		if(!(s[i]-'0')) f=1;	
	}
	if(!f||m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
}

