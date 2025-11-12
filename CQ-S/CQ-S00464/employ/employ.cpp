#include<bits/stdc++.h>
#define ll long long
#define rep(i, j, k) for(int i=(j);i<=(k);++i)
#define rep1(i, j, k) for(int i=(k);i>=(j);--i) 
#define pii pair<int, int>
#define pb push_back
#define ft first
#define sd second

using namespace std;

int read(){
	int s=0, h=1;
	char x=getchar();
	while(!isdigit(x)){
		if(x=='-') h=-1;
		x=getchar();
	}
	while(isdigit(x)){
		s=(s<<3)+(s<<1)+x-'0';
		x=getchar();
	}
	return s*h;
}

void write(int x){
	if(x<0) putchar('-'), x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=5e2+5, mod=998244353;
void add(ll &a, ll b){
	a+=b;
	if(a>=mod) a-=mod;
}
int n, m;
char s[N];
bool a[N];
int c[N];

ll f[N];

int cnt=0;
int p[N];

int l[N];

int main(){
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	n=read(), m=read();
	scanf("%s", s+1);
	rep(i, 1, n) a[i]=s[i]-'0';
	rep(i, 1, n) c[i]=read();
	
	sort(c+1, c+n+1);
	
	rep(i, 1, n){
		if(!a[i]) continue;
		p[++cnt]=i;
	}
	
	int j=n;
	c[0]=0, c[n+1]=n+1;
	rep(i, 0, n) rep(j, c[i], c[i+1]-1) l[j]=i;
	
//	cout<<"???"<<endl;
	
	f[0]=1;
	rep(j, 1, cnt){
		rep1(k, 0, j-1){
			if(!f[k]) continue;
			add(f[k+1], max(0, l[p[j]-j+k]-k)*f[k]%mod);
		}
//		rep(k, 0, j){
//			cout<<j<<" "<<k<<":"<<f[k]<<endl;
//		}
	}
	
	rep(k, 0, cnt){
		rep(i, 1, n-k){
			f[k]=f[k]*i%mod;
		}
	}
	
	rep1(k, 0, cnt) rep(j, k+1, cnt) add(f[k], mod-f[j]);
	
//	rep(i, 0, cnt){
//		cout<<cnt-i<<":"<<f[i]<<endl;
//	}
	
	ll ans=0;
	rep(k, 0, cnt-m) add(ans, f[k]);
	
	cout<<ans<<endl;
	
	return 0;
}// G
/*

3 0
111
0 1 1

*/
