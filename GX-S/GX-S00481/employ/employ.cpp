#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int read()
{
	register int x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9')
		x=x*10+c-48,c=getchar();
	return x;
}
string s;
int n,m,a[100010],ans=1,cnt=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==0) cnt++;
	}
	if(n-m+1==cnt) {cout<<1; return 0;}
	if(n-m+1<cnt){cout<<0; return 0;}
	for(int i=n;i>=1;i--)
		ans=ans*i%mod;
	cout<<ans;
	return 0;
}
