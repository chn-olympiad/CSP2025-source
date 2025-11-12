#include<bits/stdc++.h>
#define ll long long
#define cin std::cin
#define cout std::cout
#define IOS cin.tie(nullptr)->sync_with_stdio(false);
const int N=1e6+5;
int T;
int n;
struct node{
	int a,b,c;
	int maxid;
	bool cse;
};
node G[N];
int dj[N];
bool cmp(node x,node y){
	if(x.a==y.a){
		if(x.b==y.b){
			return x.c>y.c;
		}else{
			return x.b>y.b;
		}
	}
	return x.a>y.a;
}
void init(){
	for(int i=1;i<=N;i++){
		G[i].a=G[i].b=G[i].c=0;
	}
}
void solve(){
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		cin>>G[i].a>>G[i].b>>G[i].c;
		int now=std::max({G[i].a,G[i].b,G[i].c});
		if(G[i].a==now){
			G[i].maxid=1;
		}else if(G[i].b==now){
			G[i].maxid=2;
		}else{
			G[i].maxid=3;
		}
		G[i].cse=false;
	}
	std::sort(G+1,G+1+n,cmp);
	int cnta,cntb,cntc;
	int idxa,idxb,idxc;
	ll ans=0;
	cnta=cntb=cntc=0;
	int maxn=n/2;
	for(int i=1;i<=n;i++){
		if(G[i].maxid==1){
			ans+=G[i].a;
			cnta++;
			if(cnta==maxn){
				idxa=i;
			}
		} 
		if(G[i].maxid==2){
			ans+=G[i].b;
			cntb++;
			if(cntb==maxn){
				idxb=i;
			}
		} 
		if(G[i].maxid==3){
			ans+=G[i].c;
			cntc++;
			if(cntc==maxn){
				idxc=i;
			}
		} 
	}
	if(cnta>maxn){
		int ned=cnta-maxn;
		int cnt=1;
		memset(dj,0,sizeof(dj));
		for(int i=1;i<=n;i++){
			if(G[i].maxid==1){
				dj[cnt]=std::min((G[i].a-G[i].b),(G[i].a-G[i].c));
				cnt++;
			}
		}
		std::sort(dj,dj+cnt);
		for(int i=1;i<=ned;i++){
			ans-=dj[i];
		} 
	}else if(cntb>maxn){
		int ned=cntb-maxn;
		int cnt=1;
		memset(dj,0,sizeof(dj));
		for(int i=1;i<=n;i++){
			if(G[i].maxid==2){
				dj[cnt]=std::min((G[i].b-G[i].a),(G[i].b-G[i].c));
				cnt++;
			}
		}
		std::sort(dj,dj+cnt);
		for(int i=1;i<=ned;i++){
			ans-=dj[i];
		} 
	}else if(cntc>maxn){
		int ned=cntc-maxn;
		int cnt=1;
		memset(dj,0,sizeof(dj));
		for(int i=1;i<=n;i++){
			if(G[i].maxid==3){
				dj[cnt]=std::min((G[i].c-G[i].a),(G[i].c-G[i].b));
				cnt++;
			}
		}
		std::sort(dj,dj+cnt);
		for(int i=1;i<=ned;i++){
			ans-=dj[i];
		} 
	}
	cout<<ans<<'\n';
}
int main(){
	IOS;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
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
*/
/*
1
6
4 9 3
2 8 3
2 7 2
2 6 2
2 5 2
2 4 2

30

1
4
8 3 4
7 1 6
6 1 2
5 1 3

23
*/

