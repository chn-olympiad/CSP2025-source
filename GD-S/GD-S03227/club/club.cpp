#include<cstring>
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define int LL
#define For(i,t,n) for(int i=t;i<=n;++i)
#define foR(i,t,n) for(int i=t;i>=n;--i)

namespace th666{
	struct input{
		#define gc getchar
		template<typename T>
		void read(T &x){
			x=0; signed f=1,ch=gc();
			while(ch<48||ch>57){
				if(ch==EOF) return;
				if(ch==45) f=-1;
				ch=gc();
			}
			while(ch>=48&&ch<=57){
				if(ch==EOF) break;
				x=(x<<3)+(x<<1)+(ch^48);
				ch=gc();
			}
			x*=f;
		}
		template<typename T>
		input& operator>>(T &x){
			read(x); return (*this);
		}
		#undef gc
	}tin;
	struct output{
		template<typename T>
		void write(T x){
			signed stk[55],top=0;
			if(x<0) x=-x,putchar(45);
			do{stk[++top]=x%10;x/=10;}while(x);
			while(top){putchar(stk[top--]|48);}
		}
		template<typename T>
		void write(T *x){
			while(*x) putchar(*(x++));
		}
		void write(const char&x){
			putchar(x);
		}
		template<typename T>
		output& operator<<(const T&x){
			write(x); return(*this);
		}
	}tout;
};
using th666::tin;
using th666::tout;

const int MAXN=1e5+5;
int n,m,ans;
int a[MAXN][5];
struct node{
	int s,id;
	bool operator<(const node&b)const{
		return s>b.s;
	}
};
priority_queue<node> q[5];

void insertq111(int i){
		int id=1,mx=a[i][1];
		if(a[i][2]>mx) id=2,mx=a[i][2];
		if(a[i][3]>mx) id=3,mx=a[i][3];
		if((int)q[id].size()<n/2) q[id].push((node){mx,i});
		else{
			node tt=q[id].top();
			int tmp=tt.s;
			if(mx>tmp){
				q[id].pop();
				q[id].push((node){mx,i});
				insertq111(tt.id);
			}else{
				if(id==1){
					id=2,mx=a[i][2];
					if(a[i][3]>mx) id=3,mx=a[i][3];
					
					if((int)q[id].size()<n/2) q[id].push((node){mx,i});
					else{
						node ttt=q[id].top();
						int tmp2=ttt.s;
						if(mx>tmp2){
							q[id].pop();
							q[id].push((node){mx,i});
							insertq111(ttt.id);
						}else{
							if(id==2) q[3].push((node){a[i][3],i});
							else q[2].push((node){a[i][2],i});					
						}
					}//id==1	
				}else if(id==2){
					id=1,mx=a[i][1];
					if(a[i][3]>mx) id=3,mx=a[i][3];
					
					if((int)q[id].size()<n/2) q[id].push((node){mx,i});
					else{
						node ttt=q[id].top();
						int tmp2=ttt.s;
						if(mx>tmp2){
							q[id].pop();
							q[id].push((node){mx,i});
							insertq111(ttt.id);
						}else{
							if(id==1) q[3].push((node){a[i][3],i});
							else q[1].push((node){a[i][1],i});					
						}
					}//id==2					
				}else{
					id=1,mx=a[i][1];
					if(a[i][2]>mx) id=2,mx=a[i][2];
					
					if((int)q[id].size()<n/2) q[id].push((node){mx,i});
					else{
						node ttt=q[id].top();
						int tmp2=ttt.s;
						if(mx>tmp2){
							q[id].pop();
							q[id].push((node){mx,i});
							insertq111(ttt.id);
						}else{
							if(id==1) q[2].push((node){a[i][2],i});
							else q[1].push((node){a[i][1],i});					
						}
					}//id==3					
				}
			}
		}	
}

void solve1(){
	For(i,1,n){
		insertq111(i);
	}
//	cerr<<"#1:\n";
	while(q[1].size()){
//		cerr<<"a["<<q[1].top().id<<"][1]="<<q[1].top().s<<'\n';
		ans+=q[1].top().s;
		q[1].pop();
	}
//	cerr<<"#2:\n";
	while(q[2].size()){
//		cerr<<"a["<<q[2].top().id<<"][2]="<<q[2].top().s<<'\n';
		ans+=q[2].top().s;
		q[2].pop();
	}
//	cerr<<"#3:\n";
	while(q[3].size()){
//		cerr<<"a["<<q[3].top().id<<"][3]="<<q[3].top().s<<'\n';
		ans+=q[3].top().s;
		q[3].pop();
	}
//	cerr<<"ans="<<ans<<'\n';	
}

int s[5],guji[MAXN];
void dfs(int k,int w){
	if(guji[k]+w<=ans) return;
	if(k==n+1){
		ans=max(ans,w);
		return;
	}
	For(i,1,3){
		if(s[i]>=n/2) continue;
		s[i]++;
		dfs(k+1,w+a[k][i]);
		--s[i];
	}	
}

void solve2(){
	foR(i,n,1) guji[i]=guji[i+1]+max({a[i][1],a[i][2],a[i][3]});
	dfs(1,0);
}

void solve(){
	tin>>n; ans=0;
	For(i,1,n){
		tin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	if(n>30) 
		solve1();
	else solve2();
	tout<<ans<<'\n';
}
#define thlog5
signed main(){
	//rp=inf
#ifdef thlog5
	#define TimuMingzi "club"
	freopen(TimuMingzi".in","r",stdin);
	freopen(TimuMingzi".out","w",stdout);
#endif
	int t;tin>>t;
	For(i,1,t){
//		cerr<<"Case #"<<i<<"\n";
		solve();
//		cerr<<"\n\n";
	} 
	return 0;
}

