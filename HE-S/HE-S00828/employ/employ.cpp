#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
	int x=0,c=getchar(),f=0;
	for(;c<'0'||c>'9';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c-'0');
	return f?-x:x;
}

inline void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int n,m;
string s;
int len;
int c[100005];
const int mod=998244353;
int ans=0;
int p[20];

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	len=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];

	for(int i=1;i<=n;i++) p[i]=i;
	do{
		int cnt=0,nw=0;
		// for(int i=1;i<=n;i++) cout<<p[i]<<" ";
		// cout<<"\n";
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||cnt>=c[p[i]]) cnt++;
			else nw++;//,cout<<i<<" ";
		}
		// cout<<"\n";
		// if(nw>=m) cout<<"Yes\n";
		// cout<<"\n\n\n\n";
		ans+=nw>=m;
	}while(next_permutation(p+1,p+1+n));

	cout<<ans%mod<<"\n";

	return 0;
}