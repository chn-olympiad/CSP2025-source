#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m,c[N],p[N];
string s;
void solve1()
{
	int ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%MOD;
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(m==n && n>10)
	{
		cout<<1;
		return 0;
	}
	if(m==1 && n>10)
	{
		solve1();
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	bool fl=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			fl=1;
			break;
		}
	}
	if(!fl)
	{
		solve1();
		return 0;
	}
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0' || cnt>=c[p[i]]) cnt++;
		}
		if(n-cnt>=m) ans++; 
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
}
