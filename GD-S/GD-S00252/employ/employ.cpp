//t4 (rp<<=rp)<<=rp
#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
const int MOD=998244353;
int n,m,p[N],a[N],id[N];
long long ans;
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		id[i]=i;
	}
	if(n<=10)
	{
		do{
			for(int i=1;i<=n;++i)p[i]=a[id[i]];
			int d=0,cnt=0;
			for(int i=1;i<=n;++i)
			{
				if(d>=p[i])d++;
				else if(s[i]=='0')d++;
				else cnt++;
			}
			if(cnt>=m)ans=(ans+1)%MOD;
		}while(next_permutation(id+1,id+n+1));
		cout<<ans;
		return 0;
	}
	else if(m==n)
	{
		bool flag=1;
		ans=1;
		for(int i=1;i<=n;++i)if(s[i]=='0')flag=0;
		for(int i=1;i<=n;++i)if(a[i]==0)flag=0;
		for(int i=1;i<=n;++i)ans=(ans*i)%MOD;
		cout<<(flag?ans:0);
		return 0;
	}
	else cout<<0;
	return 0;
} 
