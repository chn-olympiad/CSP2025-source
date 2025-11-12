#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getchar();
	cin>>s;
	for(int i=0; i<s.size(); i++)if(s[i]=='0')t++;
	if(t!=0)
	{
		if(n-m-t>0)
		{
			for(int i=1; i<=n; i++)
				ans*=i,ans%=998244353;
			cout<<ans;
		}
		else cout<<1;
	}
	else 
	{
		for(int i=1; i<=n; i++)
			ans*=i,ans%=998244353;
		cout<<ans;
	}
	return 0;
} 
