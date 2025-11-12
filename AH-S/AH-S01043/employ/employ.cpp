#include <bits/stdc++.h>
#define re register
using namespace std;
int main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m; cin>>n>>m;
	bool flag=false;
	if(m==n) flag=true;
	string s; cin>>s;
	bool is1=true;
	for(re int i=1;i<s.size();++i)if(s[i]=='0'){is1=false;break;}
	int cnt=0;
	for(re int i=1;i<=m;++i) 
	{
		int x; cin>>x;
		if(x) ++cnt;
	}
	if(flag) 
	{
		if(is1) cnt=n;
		else puts("0");
	}
	long long ans=1;
	for(re int i=1;i<=cnt;++i) ans=ans*i%998244353;
	cout<<ans;
	return 0;
}
