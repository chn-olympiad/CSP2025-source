#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;

int n;
int a[N][4];

struct qwq{
	int sum,i;
}e[N];
int tot=0;
bool cmp(const qwq &x,const qwq &y){
	return x.sum>y.sum;
}

int zans=0;
bool bk[N];

void Solve2(int x,int y){
	for(int i=1;i<=n;i++)
		if(!bk[i])
			zans+=max(a[i][x],a[i][y]);
	return;
}

void Solve1(){
	int mx=0; tot=0;
	for(int i=1;i<=n;i++){
		e[++tot].i=i;
		e[tot].sum=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		if(e[i].sum>=0){
			zans+=a[e[i].i][1];
			mx++;
			bk[e[i].i]=1;
		}
		else break;
		if(mx*2==n) break;
	}	
	if(mx*2==n){
		Solve2(2,3);
		return;
	}
	mx=0; tot=0;
	for(int i=1;i<=n;i++){
		if(bk[i]) continue;
		e[++tot].i=i;
		e[tot].sum=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		if(e[i].sum>=0){
			zans+=a[e[i].i][2];
			mx++;
			bk[e[i].i]=1;
		}
		else break;
		if(mx*2==n) break;
	}		
	if(mx*2==n){
		Solve2(1,3);
		return;
	}	
	mx=0; tot=0;
	for(int i=1;i<=n;i++){
		if(bk[i]) continue;
		e[++tot].i=i;
		e[tot].sum=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		if(e[i].sum>=0){
			zans+=a[e[i].i][3];
			mx++;
			bk[e[i].i]=1;
		}
		else break;
		if(mx*2==n) break;
	}		
	if(mx*2==n){
		Solve2(1,2);
		return;
	}		
	return;
}

void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			scanf("%d",&a[i][j]);
	Solve1();
	printf("%d\n",zans);
	zans=0; // qingkong
	for(int i=1;i<=n;i++) bk[i]=0;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	
	int T;
	scanf("%d",&T);
	while(T--){
		Solve();
	}
	return 0;
}

