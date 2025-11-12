#include<bits/stdc++.h>
#define F(i,a,b) for( int i=a; i<=b; i++)
#define FF(i,a,b) for ( int i=a; i>=b; i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define emb(x) emplace_back(x) 
using ll =long long;
using ull =unsigned long long;
using db =double;
using ldb =long double;
const int MAXN =2e5+5;

using namespace std;
struct Node{
	int val,id;
}b[4][MAXN];
int n,a[MAXN][4],cnt[4],rcd[4][MAXN];
bool vis[4][MAXN];
ll ans;
//rcd 排序前 -> 排序后

namespace sub2{
	void calc( int id) {
		int p[4] ={0,1,1,1},tot =1,tmp =0;
		ll res =0;
		memset(cnt,0,sizeof(cnt)),mem(vis,0);
		if ( id ==1) res +=b[1][1].val,p[1] =2,tmp =b[1][1].id,cnt[1] =1;
		else if ( id==2) res +=b[2][1].val,p[2] =2,tmp =b[2][1].id,cnt[2] =1;
		else res +=b[3][1].val,p[3] =2,tmp =b[3][1].id,cnt[3] =1;
		F ( i,1,3) vis[i][rcd[i][tmp]] =1;
		while ( tot<n) {
			int mx =0,id1 =0,id2 =0;
			while ( p[1] <=n && vis[1][p[1]]) ++p[1];
			while ( p[2] <=n && vis[2][p[2]]) ++p[2];
			while ( p[3] <=n && vis[3][p[3]]) ++p[3];	
			//找到没有被标记的最大下标 (p 存储排序后的下标)
 			F ( i,1,3) { 
				if ( cnt[i] >=n/2) continue;
				//大于  
				if ( mx <b[i][p[i]].val) {
					mx =b[i][p[i]].val,id2 =i;
					id1 =b[i][p[i]].id;
				}
				else if ( mx ==b[i][p[i]].val && cnt[i] <cnt[id]) {
					mx =b[i][p[i]].val,id2 =i;
					id1 =b[i][p[i]].id;
				}
			}
			// 找最大 
			if ( !id1) continue;
			++tot,++cnt[id2];
			res +=mx;
			F ( i,1,3) vis[i][rcd[i][id1]] =1;
		}
		ans =max(ans,res);
	}
	void solve() {
		cin >>n;  ans =0;
		F ( i,1,n) cin >>a[i][1] >>a[i][2] >>a[i][3];
		F ( i,1,n) {
			b[1][i] ={a[i][1],i};
			b[2][i] ={a[i][2],i};
			b[3][i] ={a[i][3],i};
		}
		sort(b[1]+1,b[1]+1+n,[](Node x,Node y) {return x.val >y.val;});
		sort(b[2]+1,b[2]+1+n,[](Node x,Node y) {return x.val >y.val;});
		sort(b[3]+1,b[3]+1+n,[](Node x,Node y) {return x.val >y.val;});
		F ( i,1,3) {
			F ( j,1,n) rcd[i][b[i][j].id] =j;
		}
		calc(1),calc(2),calc(3);
		cout <<ans <<'\n';
	}	
}

namespace sub1{
	bool vis[MAXN];
	void calc( int x) {
		ll res =0; mem(vis,0);
		F ( i,1,n/2) {
			res +=b[x][i].val,vis[b[x][i].id] =1;
		}
		if ( n==2) {
			int p =1;
			while ( vis[p] && p <n) ++p;
			int mx =0;
			F ( i,1,3) {
				if ( x ==i) continue;
				mx =(mx >b[i][p].val? mx:b[i][p].val);
			} 
			res +=mx; ans =max(ans,res);
			return;
		}
		int p =1,tot =0;
		F ( i,1,n) {
			if ( vis[i]) continue;
			int mx =0;
			F ( j,1,3) {
				if ( j ==x) continue;
				mx =max(mx,a[i][j]);
			}
			res +=mx;
		}
		ans =max(ans,res);
	}
	void solve() {
		cin >>n;  ans =0;
		F ( i,1,n) cin >>a[i][1] >>a[i][2] >>a[i][3];
		F ( i,1,n) {
			b[1][i] ={a[i][1],i};
			b[2][i] ={a[i][2],i};
			b[3][i] ={a[i][3],i};
		}
		sort(b[1]+1,b[1]+1+n,[](Node x,Node y) {return x.val >y.val;});
		sort(b[2]+1,b[2]+1+n,[](Node x,Node y) {return x.val >y.val;});
		sort(b[3]+1,b[3]+1+n,[](Node x,Node y) {return x.val >y.val;});	
		calc(1),calc(2),calc(3);	
		cout <<ans <<'\n';
	}
}
 
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T; cin >>T;
	while ( T--) sub2::solve();
	
	return 0;
}
/****
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13

1
2
10 9 8
4 0 0
****/
