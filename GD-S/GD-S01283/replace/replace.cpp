#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,p;
string s[3][N];
string t[3][N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("peplace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>s[1][i]>>s[2][i];
	}
	for(int i=1;i<=p;i++)
	{
		cin>>t[1][i]>>t[2][i];
	}
	return 0;
}
