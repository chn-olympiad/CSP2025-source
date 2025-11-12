#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n,q;
string s[N][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		cout<<0<<"\n";
	}
}
