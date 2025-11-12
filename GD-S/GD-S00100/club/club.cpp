#include <bits/stdc++.h>

using namespace std;

#define N (int)(1e5+10)

int T;
int tmp[5],tot[5];

struct node{
	int a,b,c;
	int mx1,mx2;
	int d;
}h[N];

inline bool cmp(node x,node y){
	if(x.d==y.d) return x.mx1>y.mx1;
	return x.d>y.d;
}

inline void solve(){
	int n,ans=0;
	tot[1]=tot[2]=tot[3]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d %d %d",&h[i].a,&h[i].b,&h[i].c);
		tmp[1]=h[i].a;
		tmp[2]=h[i].b;
		tmp[3]=h[i].c;
		sort(tmp+1,tmp+4);
		h[i].d=tmp[3]-tmp[2];
		h[i].mx1=tmp[3];
		h[i].mx2=tmp[2];
	}
	sort(h+1,h+n+1,cmp);
	for(int i=1;i<=n;++i){
		int fl=0,qwq=0;
		if(h[i].mx1==h[i].a) fl=1;
		if(h[i].mx1==h[i].b) fl=2;
		if(h[i].mx1==h[i].c) fl=3;
		if(h[i].mx2==h[i].a) qwq=1;
		if(h[i].mx2==h[i].b) qwq=2;
		if(h[i].mx2==h[i].c) qwq=3;
		if(tot[fl]<(n/2)){
			++tot[fl];
			ans+=h[i].mx1;
		}
		else{
			++tot[qwq];
			ans+=h[i].mx2;
		}
	}
	printf("%d\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		solve();
	}
	fclose(stdin);fclose(stdout);
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
