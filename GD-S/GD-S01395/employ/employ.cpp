#include<bits/stdc++.h> 
#define int long long
#define up(i,l,r) for(int i=l; i<=r; ++i)
#define dn(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back

using namespace std;

const int N=505, P=998244353;

int n, m, s[N], c[N];
char str[N];

struct SUB1 {
	int Ans, tag[N], p[N];
	void dfs(int x) {
		if(x>n) {
			int pre=0, cnt=0;
			up(i,1,n) {
				if(s[i]==0||c[p[i]]<=pre) ++pre;
				else ++cnt;
			}
			Ans+=(cnt>=m);
			return;
		}
		up(i,1,n) {
			if(tag[i]) continue;
			tag[i]=1;
			p[x]=i, dfs(x+1);
			tag[i]=0;
		}
	}
	void mian() {
		dfs(1);
		cout << Ans << '\n';
		exit(0);
	}
} Sub1;

struct SUB2 {
	
	void mian() {
		int j=0, Ans=1;
		up(i,1,n) if(c[i]) { j=i-1; break; }
		if(n-j<m) { cout << 0 << '\n'; exit(0); }
		up(i,j+1,n) {
			if(c[i]>j) {
				Ans=Ans*(j+i-j-1+1)%P;
			}
			else {
				Ans=Ans*(c[i]-1+i-j-1+1)%P;
			}
		}
		up(i,1,j) Ans=Ans*i%P;
		cout << Ans << '\n';
		exit(0);
	}
} Sub2;

struct SUB3 {
	int g[1<<29], num[N], cnt[N], fac[N][N];
	int C(int n,int m) {
		if(m<0||n<m) return 0;
		return fac[n][m];
	}
	void add(int &a,int b) {
		a=(a+b)%P;
	}
	void mian() {
		up(i,0,n) {
			fac[i][0]=fac[i][i]=1;
			up(j,1,i-1) fac[i][j]=(fac[i-1][j-1]+fac[i-1][j])%P;
		}
		int tot=0;
		up(i,1,n) if(s[i]) num[i]=++tot;
		up(S,0,(1<<tot)-1) {
			memset(cnt,0,sizeof(cnt));
			int awa=0, pre=0, lst=0;
			up(i,1,n) {
				if(s[i]&&(S>>(num[i]-1)&1)) {
					up(j,1,n) if(c[j]>pre) ++cnt[i];
					++awa;
					g[S]=g[S]*(cnt[i]-lst)%P;
					lst=cnt[i];
				}
				else ++pre;
			}
			up(i,1,n-awa) g[S]=g[S]*i%P;
			if((tot-awa)%2==0) Add(Ans,g[S]*C(tot,awa)%P);
			else  Add(Ans,-g[S]*C(tot,awa)%P);
		}
		cout << (Ans%P+P)%P << '\n';
		exit(0);
	}
};

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> (str+1);
	up(i,1,n) s[i]=str[i]-'0';
	up(i,1,n) cin >> c[i];

//	srand((unsigned)time(0));
//	n=8, m=rand()%n+1;
//	up(i,1,n) s[i]=1;
//	up(i,1,n) c[i]=rand()%(n+1);
//	
//	cout << n << ' ' << m << '\n';
//	up(i,1,n) cout << c[i] << ' '; cout << '\n';
	
	sort(c+1,c+1+n);
	
	if(m==n) {
		bool flag=0;
		up(i,1,n) if(s[i]==0||c[i]==0) flag=1;
		if(flag) {
			cout << 0 << '\n';
			return 0;
		}
	}
	
	if(n<=10) Sub1.mian();
	
	bool flag=1;
	up(i,1,n) if(s[i]==0) flag=0;
	if(flag) Sub2.mian();
	
	Sub3.mian();
	
	return 0;
}
