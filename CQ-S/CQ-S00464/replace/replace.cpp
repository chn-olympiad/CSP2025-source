/*

不是哥们，真tm考AC自动机啊
乌鸦嘴ph啊卧槽 

。。

等下，这真的不是广义SAM吗 

*/
#include<bits/stdc++.h>
#define ll long long
#define rep(i, j, k) for(int i=(j);i<=(k);++i)
#define rep1(i, j, k) for(int i=(k);i<=(j);--i) 
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

const int N=2e5+5, M=2.5e6+5, mod[2]={20090303, 998244353};
int n, q;
char c[2][M];
vector<char> s[N][2];
vector<char> t[N][2];

//ll sum[2][M][2][2], d[M][2];

//int tr[2][M][26];
//int fail[2][M];
//int tot[2];
//void build(){
//	
//	int len=strlen(c[0]+1);
//	rep(p, 0, 1){
//		rep(i, 0, tot[p]){
//			fail[p][i]=0;
//			rep(j, 0, 25) tr[p][i][j]=0;
//		}
//		tot[p]=0;
//		
//		int x=0;
//		rep(i, 1, len){
//			int y=c[p][i]-'a';
//			if(tr[p][x][y]){
//				x=tr[p][x][y];
//				continue;
//			}
//			int nw=++tot[p];
//			while(x && !tr[p][fail[p][x]][y]) 
//				tr[p][x][y]=nw, x=fail[p][x];
//			if(!x) fail[p][nw]=0, tr[p][0][y]=nw;
//			else fail[p][nw]=tr[p][fail[p][x]][y];
//		}
//	}
//	
//}

//int sp[N][2], st[N][2];
//vector<pii> v[M<<1];
//
//int stk[N], top;
//
//int ycl[N], mx;
//void add(int u){
//	
//}
//vector<int> bt[M<<1];

//ll calc(int p, int i, int j, int len, int pp){
//	return (sum[p][i][j+len-1][pp]-sum[p][i][j-1][pp]*d[len][pp]%mod[pp]+mod[pp])%mod[pp];
//}
//
//bool chk(int i, int j, int k){
//	int len=s[i][0].size();
//	rep(p, 0, 1) if(calc(0, i, 1, len, p)^calc(1, j, k, len, p)) return 0;
//	rep(p, 0, 1) if(calc(0, i, 1, len, p)^calc(1, j, k, len, p)) return 0;
//}

int main(){
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
//	bool flg=1;
	n=read(), q=read();
	while(q--) cout<<0<<endl;
//	rep(i, 1, n){
//		rep(j, 0, 1){
//			scanf("%s", c[j]+1);
//			int len=strlen(c[j]+1);
//			rep(k, 1, len) s[i][j].pb(c[j][k]);
//			rep(k, 1, len){
//				rep(p, 0, 1){
//					sum[0][k][j][p]=(sum[0][k-1][j][p]*31+c[j][k]-'a')%mod[p];
//				}
//			}
//			int cnt[2];
//			cnt[0]=cnt[1]=0;
//			rep(k, 1, len){
//				if(c[j][k]>='c') flg=0;
//				else ++cnt[c[j][k]-'a'];
//				if(c[j][k]=='b') sp[i][j]=i;
//			}
//			if(cnt[1]^1) flg=0;
//		}
//	}
	
//	rep(i, 1, q){
//		rep(j, 0, 1){
//			scanf("%s", c[j]+1);
//			int len=strlen(c[j]+1);
//			rep(k, 1, len) t[i][j].pb(c[j][k]);
//			rep(k, 1, len){
//				rep(p, 0, 1){
//					sum[1][k][j][p]=(sum[1][k-1][j][p]*31+c[j][k]-'a')%mod[p];
//				}
//			}
//			int cnt[2];
//			cnt[0]=cnt[1]=0;
//			rep(k, 1, len){
//				if(c[j][k]>='c') flg=0;
//				else ++cnt[c[j][k]-'a'];
//				if(c[j][k]=='b') st[i][j]=i;
//			}
//			if(cnt[1]^1) flg=0;
//		}
		
//		build();
		
//	}
	
//	rep(i, 1, M-5) rep(j, 0, 1) d[i][j]=d[i-1][j]*31%mod[j];
	
//	if(flg){
//		
//		rep(i, 1, n){
//			stk[++top]=sp[i][0]-sp[i][1]+M-5;
//			v[sp[i][0]-sp[i][1]+M-5].pb({sp[i][0]-1, (int)s[i].size()-sp[i][0]});
//		}
//		sort(stk+1, stk+top+1);
//		int ttt=0;
//		rep(i, 1, top){
//			if(stk[ttt]^stk[i]) stk[++ttt]=stk[i];
//		} top=ttt;
//		
//		rep(i, 1, top){
//			int id=stk[i];
//			mx=v[id].size();
//			
//			
//		}
//		
//		
//	}else{
		
//		rep(i, 1, q){
//			int l=0, r=t[i][0].size()-1;
//			while(l<=r){
//				if(t[i][0][l]==t[i][1][l]) ++l;
//				else break;
//			}
//			while(l<=r){
//				if(t[i][0][r]==t[i][1][r]) --r;
//				else break;
//			}
//			int mx=t[i][0].size()-1;
//			int ans=0;
//			rep(j, 1, n){
//				int len=s[i][0].size();
//				rep(k, 0, l){
//					if(k+len-1<r) continue;
//					if(k+len-1>mx) continue;
//					if(chk(j, i, k)) ++ans;
//				}
//			}
//			cout<<ans<<endl;
			
	//		build();
			
//		}
		
		
//	}
	
	return 0;
}// g
