#include<bits/stdc++.h>
#define int128 __int128
using namespace std;
const int N=2e5+10;
const int128 inf=18446744073709551615;
struct S{
	string a;
	string b;
	int len=0;
}s[N],t[N];
int cnt[N];
int n,q;
void solve2()
{
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		int len=t[i].len;
		for(int j=1;j<=n;j++)
		{
			string x=t[i].a;
			string y=s[j].a;
			string u=t[i].b;
			string v=s[j].b;
			cout<<x<<" "<<y<<" "<<x.find(y)<<endl;
			cout<<u<<" "<<v<<" "<<u.find(v)<<endl;
			if(x.find(y)!=inf&&u.find(v)!=inf) ans++;
		}
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a;
		cin>>s[i].b;
		s[i].len=s[i].a.length();
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i].a;
		cin>>t[i].b;
		t[i].len=t[i].a.length();
	}
	//for(int i=1;i<=q;i++) cout<<t[i].a<<" "<<t[i].b<<endl;
	solve2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}