#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;
ll T,rans,a[MAXN][4],n,number[4],pos_ans;
bool pos_flag;
void choice(ll x,ll ans){
	if(x==n+1){
		rans=max(rans,ans);
		return;
	}
//	choice(x+1,ans);
	for(ll i=1;i<=3;++i){
		number[i]++;
		if(number[i]>n/2){
			number[i]--;
			continue;
		}
		choice(x+1,ans+a[x][i]);
		--number[i];
	}
}
struct pi{
	ll l,r;
	bool operator<(const pi&o)const{
		if(l!=o.l)return l<o.l;
		else return r<o.r;
	}
	bool operator==(const pi&o)const{
		return l==o.l&&r==o.r;
	}
}A[MAXN],B[MAXN],lx,ly;
priority_queue<pi>G1,G2;
void solve(){
	for(ll i=1;i<=n;++i){
		A[i].l=a[i][1],A[i].r=a[i][2];
	}
	std::sort(A+1,A+n+1);
	while(!G1.empty()){
		G1.pop();
//		printf("%lld",G1.top().l);
	}
	while(!G2.empty()){
		G2.pop();
//		printf("%lld",G1.top().l);
	}
	for(ll i=1;i<=n/2;++i){
//		G1.push(pi{-A[i].l,A[i].r});
		rans+=A[i].l;
//		G1[i]=A[i].l,G1[i].r=A[i].r;
	}
	for(ll i=n/2+1;i<=n;++i){
		G2.push(A[i]);
		rans+=A[i].r;
//		G2[i]=A[i].l,G2[i].r=A[i].r;
	}
	while(1){
		pi x=G1.top();
		pi y=G2.top();
		if(lx==x&&ly==y)break;
		if(x.l+y.r<x.r+y.l){
			rans=rans-(x.l+y.r)+(x.r+y.l);
			G1.pop(),G2.pop();
			G1.push(y),G2.push(x);
//			printf("%lld\n",ans);
		}
		lx=y,ly=x;
	}
}
/*
3
4
0 1 0
0 1 0
0 2 0
0 2 0
4
4 2 1
3 2 4
5 3 4
3 5 1
2
10 9 8
4 0 0

*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		rans=number[1]=number[2]=number[3]=pos_ans=0;
		pos_flag=true;
		scanf("%lld",&n);
		for(ll i=1;i<=n;++i){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][3]!=0)pos_flag=false;
			pos_ans+=max(a[i][1],a[i][2]);
		}
//		if(pos_flag)
		if(n<=10)choice(1,0);
		else solve();
		printf("%lld\n",rans);
	}
	return 0;
}
