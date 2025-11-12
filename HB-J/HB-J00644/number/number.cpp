/*
100 pts
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e7;
int a[MAXN];
int cnt;
char s[MAXN];
inline bool cmp(int A,int B)
{
	return A>B;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;++i)
	{
		if(isdigit(s[i]))
		{
			cnt++;
			a[cnt]=s[i]-48;
		}
	}
	stable_sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;++i) cout<<a[i];
	return 0;
}