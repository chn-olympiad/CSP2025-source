#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s1[N],s2[N],t1,t2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++)
		{
			if(t1[i]!=t2[i]) ans++;
		}
		if(ans==t1.size()) cout<<0<<'\n';
		else cout<<ans<<'\n';
	}
	return 0;
}
