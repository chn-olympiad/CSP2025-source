#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,ans;
string s1,s2,s3,s4;
map<string,int> mp1,mp2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		mp1[s1]++;
		mp2[s2]++;
	}
	while(q--)
	{
		cin>>s3>>s4;
		cout<<min(mp1[s3],mp2[s4])<<'\n';
	}
	return 0;
}
