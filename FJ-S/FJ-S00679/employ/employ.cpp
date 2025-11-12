#include<bits/stdc++.h>
#define N 505
using namespace std;
int n,m,c[N],ans,p[N];
string s;
bool check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>=c[p[i]]||s[i-1]=='0') cnt++;
	}
	return n-cnt>=m;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	do
	{
		if(check()) ans++;
	}
	while(next_permutation(p+1,p+n+1));
	cout<<ans<<'\n';
	return 0;
}

