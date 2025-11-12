#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s1[N],s2[N];
string t1,t2;
int dp[N][N];
int ans=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--)
	{
		cin>>t1>>t2;
		ans=0;
		if(t1.length()!=t2.length())
		{
			cout<<0<<endl;
			continue;
		}
		else cout<<2<<endl;
	}
}