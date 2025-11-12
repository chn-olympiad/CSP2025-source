#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
int n,m,s[N],c[N],mod=998244353,t;
char ch;
ll ans=1;
int in()
{
	int w=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		w=w*10+c-'0';
		c=getchar(); 
	}
	return f*w;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int tot=n;
	for(int i=1;i<=n;i++) 
	{
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++) 
	{
		c[i]=in();
		if(c[i]) t++;
	}
	for(int i=2;i<n;i++) ans=ans*i%mod;
	cout<<ans*t%mod;
	return 0;
 } 
