#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
ll T,n,a[N][3],now,cnt[3];
struct nod{ll mx,cx,mx1,cx1;}p[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		now=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			ll mn=min(min(a[i][0],a[i][1]),a[i][2]);
			a[i][0]-=mn,a[i][1]-=mn,a[i][2]-=mn;
			now+=mn;
			if(a[i][0]==0) p[i]={a[i][1],a[i][2],1,2};
			else if(a[i][1]==0) p[i]={a[i][0],a[i][2],0,2};
			else if(a[i][2]==0) p[i]={a[i][1],a[i][0],1,0};
			if(p[i].mx<p[i].cx) swap(p[i].mx,p[i].cx),swap(p[i].mx1,p[i].cx1);
		}
		stable_sort(p+1,p+n+1,[](const nod &a,const nod &b){return a.mx-a.cx>b.mx-b.cx;});
		for(ll i=1;i<=n;i++){
			if(cnt[p[i].mx1]<n/2) cnt[p[i].mx1]++,now+=p[i].mx;
			else if(cnt[p[i].cx1]<n/2) cnt[p[i].cx1]++,now+=p[i].cx;
			else cnt[p[i].mx1^p[i].cx1^3]++;
		}
		printf("%lld\n",now);
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
*/
