#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000010],t[1000010],ans;
string s;
void dg(int now,int fang)
{
	if(now>n)
	{
		if(n-fang>=m) ans++,ans%=998224353;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i]==0)
		{
			t[i]=1;
			if(s[now-1]=='0'||fang>=c[i]) dg(now+1,fang+1);
			else dg(now+1,fang);
			t[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	dg(1,0);
	cout<<ans%998224353;
	return 0;
}
