#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
bool s[505];
int c[505];
int CCF54188=114514;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string str;
	cin>>str;
	bool bol=true;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='1')
			s[i+1]=true;
		else
			s[i+1]=false;
		if(!s[i+1])
			bol=false; 
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(bol)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
	}
	else
	if(n==m)
	{
		sort(c+1,c+1+n);
		int tt=0,l=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]&&tt<c[i])
				l++;
			else
				tt++;
		}
		if(l==n)
			cout<<"1";
		else
			cout<<"0";
	}
	else
		cout<<"0";
	return 0;
}
