#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss string
struct s{
	ll a,b,c,sum,y,e,s;
}xs[10005];
ll t,n,sum,ren;
bool cmp1(s x,s y){
	return x.a>y.a;
}
bool cmp2(s x,s y){
	return x.b>y.b;
}
bool cmp3(s x,s y){
	return x.c>y.c;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		ren=n/2;
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&xs[i].a,&xs[i].b,&xs[i].c);
		}
		sort(xs+1,xs+n+1,cmp1);
		for(ll i=1;i<=ren;i++){
			xs[i].sum++;
			xs[i].y=1;
		}
		sort(xs+1,xs+n+1,cmp2);
		for(ll i=1;i<=ren;i++){
			xs[i].sum++;
			xs[i].e=1;
		}
		sort(xs+1,xs+n+1,cmp3);
		for(ll i=1;i<=ren;i++){
			xs[i].sum++;
			xs[i].s=1;
		}
		for(ll i=1;i<=n;i++){
			if(xs[i].sum){
				sum+=max(max(xs[xs[i].y].a,xs[xs[i].e].b),xs[xs[i].s].c);
			}
		}
		printf("%lld\n",sum);
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
