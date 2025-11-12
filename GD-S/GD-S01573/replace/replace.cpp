#include<bits/stdc++.h>
using namespace std;

int n,q,ans;
string t1,t2;
string s1[200001],s2[200001];
void dfs(string t,int dep)
{
	if(dep>n)
	{
		if(t==t2)ans++;
		return;
	}
	if(t.find(s1[dep])<=n)
	{
//		cout<<t.substr(0,t.find(s1[dep]))+s2[dep]+t.substr(t.find(s1[dep])+s2[dep].length(),t.length()-1)<<endl;
		dfs(t.substr(0,t.find(s1[dep]))+s2[dep]+t.substr(t.find(s1[dep])+s2[dep].length(),t.length()-1),dep+1);
	}
	dfs(t,dep+1);
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		dfs(t1,1);
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
+t.substr(t.find(s1[dep])+s2[dep].length(),t.length()-1)
*/
