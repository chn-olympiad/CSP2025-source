#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
string s;
int a[15];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	FOR(i,0,s.size()-1)
	{
		int x=s[i]-'0';
		if(x>=0&&x<=9) a[x]++;
	}
	ROF(i,9,0) FOR(j,1,a[i]) cout<<i;
	return 0;
}
