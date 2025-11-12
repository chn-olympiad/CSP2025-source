#include<bits/stdc++.h>
using namespace std;

#define int ll
#define pii pair<int,int>
#define ll long long

#define For(a,b,c) for(int a=(b);a<=(c);a++)
#define Rep(a,b,c) for(int a=(b);a>=(c);a--)
const int mod = 998244353;


int read() {
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9'; ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9'; ch=getchar()) x=(x*10)+ch-'0';
	return x*f;
}

#define in1(a) a=read()
#define in2(a,b) a=read(),b=read()
#define in3(a,b,c) a=read(),b=read(),c=read()
#define in4(a,b,c,d) a=read(),b=read(),c=read(),d=read()

int qpo(int a,int b) {
	int res=1;
	while(b) {
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int n,m;
string s;
int c[505];

int p[505];

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;
	For(i,1,n) cin>>c[i];
	For(i,1,n) p[i]=i;
	int ans=0;
	do {
		int res=0;
		For(i,1,n) if(s[i]=='0'||res>=c[p[i]]) res++;
		ans+=(n-res)>=m;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<'\n';
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

