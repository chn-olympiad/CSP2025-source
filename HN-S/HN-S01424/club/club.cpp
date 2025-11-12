#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<time.h>
#include<queue>
#include<set>
#include<unordered_map>
#include<bitset>
#include<random>
#define ci const int
#define iv inline void
#define ic inline ci
#define ll long long
#define ull unsigned ll
#define int ll
#define gc getchar_unlocked
#define pc putchar
ic re();iv pr(ci x);iv prs(ci x);iv prn(ci x);
iv swp(int&a,int&b){a^=b^=a^=b;}
ic Max(ci a,ci b){return a>b?a:b;}
ic Min(ci a,ci b){return a<b?a:b;}
iv gma(int&a,ci b){a=Max(a,b);}
iv gmi(int&a,ci b){a=Min(a,b);}
ic Abs(ci a){return a<0?-a:a;}
#define N 100003
int n,ans;
struct gg{
	int v,d,opt;
	gg(ci a=0,ci b=0,ci c=0){v=a,d=b,opt=c;}
	bool operator<(const gg x)const{return d>x.d;}
};
std::priority_queue<gg>pq[3];
iv work(){
	n=re();
	ci nd2=n>>1;
	for(int i=1,a,b,c;i<=n;++i){
		a=re(),b=re(),c=re();
		if(c>=a&&c>=b){
			if(a>=b)pq[2].push(gg(c,c-a,0));
			else pq[2].push(gg(c,c-b,1));
			ans+=c;
			if(pq[2].size()>nd2){
				const gg x=pq[2].top();
				ans-=x.d;
				pq[2].pop();
				pq[x.opt].push(gg(x.v-x.d,200000,-1));
			}
		}else if(b>=a&&b>=c){
			if(a>=c)pq[1].push(gg(b,b-a,0));
			else pq[1].push(gg(b,b-c,2));
			ans+=b;
			if(pq[1].size()>nd2){
				const gg x=pq[1].top();
				ans-=x.d;
				pq[1].pop();
				pq[x.opt].push(gg(x.v-x.d,200000,-1));
			}
		}else if(a>=b&&a>=c){
			if(b>=c)pq[0].push(gg(a,a-b,1));
			else pq[0].push(gg(a,a-c,2));
			ans+=a;
			if(pq[0].size()>nd2){
				const gg x=pq[0].top();
				ans-=x.d;
				pq[0].pop();
				pq[x.opt].push(gg(x.v-x.d,200000,-1));
			}
		}
	}prn(ans);
	ans=0;
	for(int i=0;i<3;++i)
		while(!pq[i].empty())
			pq[i].pop();
}
/*
ulimit -s 10240
10 MB

20 min
20/20
*/
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int T=re();T--;)work();
}
ic re(){
	int x=0;char c=gc(),f=0;
	while(c<48||c>57)f|=(c=='-'),c=gc();
	while(c<58&&c>47)x=x*10+(c^48),c=gc();
	return f?-x:x;
}
void pri(ci x){if(x>9)pri(x/10);pc(x%10^48);}
iv pr(ci x){if(x<0)pc('-'),pri(-x);else pri(x);}
iv prs(ci x){pr(x),pc(32);}
iv prn(ci x){pr(x),pc(10);}
/*
g++ -Wall -Wextra -O2 1.cpp -o 1
Ren5Jie4Di4Ling5%
*/