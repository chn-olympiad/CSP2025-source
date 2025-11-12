#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,c[N],p[N],ans,fail;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	do
	{
		fail=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0') fail++;
			else if(fail>=c[p[i]]) fail++;
		if(n-fail>=m) ans++;
	}
	while(next_permutation(p+1,p+1+n));
	cout<<ans; 
}
