#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
using namespace std;
typedef long long ll;
const int N=1e5+91,G=5e2+5,inf=0x7fffffff;
int vis[G];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i=0;i<=int(s.size()-1);i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			vis[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		f(j,1,vis[i]) cout<<i;
	}
	return 0;
}













































































