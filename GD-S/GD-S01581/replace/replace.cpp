#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,ans,t1,t2,len;
string s[200005][3],t[200005][3],st1,st2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(ll i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
		if(t[i][1].size()!=t[i][2].size())
		{
			cout<<0<<"\n";
			continue;
		}
		ans=0;
		for(ll j=1;j<=n;j++)
		{
			if(t[i][1].size()<s[j][1].size())continue;
			t1=t[i][1].find(s[j][1],0);
			t2=t[i][2].find(s[j][2],0);
			len=s[j][1].size();
			if(t1!=-1&&t2!=-1)
			{
				st1=t[i][1];
				st2=t[i][2];
				st1.erase(t1,len);
				st2.erase(t2,len);
				if(st1==st2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
