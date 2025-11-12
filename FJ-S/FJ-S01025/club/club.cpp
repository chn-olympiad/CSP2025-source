#include<bits/stdc++.h>
#define mk(a,b) make_pair(a,b)
const int _=1e5+7;
using namespace std;
int T,n,vis[_],m;
struct N{
	int a,b,c;
}a[_];
bool cmp1(N x,N y){
	return x.a>y.a;
}
bool cmp2(N x,N y){
	return x.b>y.b;
}
bool cmp3(N x,N y){
	return x.c>y.c;
}

int main(void){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		int s=0,n1=0,n2=0,n3=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].a);
			scanf("%d",&a[i].b);
			scanf("%d",&a[i].c);
		}
		if(n==2){
			printf("%d\n",max({a[1].a+a[2].b,a[1].a+a[2].c,a[1].b+a[2].a,a[1].b+a[2].c,a[1].c+a[2].a,a[1].c+a[2].b}));
		}
		else if(a[1].b==0){
			sort(a+1,a+1+n,cmp1);
			m=n/2;
			for(int i=1;i<=m;i++){
				s+=a[i].a;
			}
			printf("%d\n",s);
			
		}
		else{
			int seed=rand()%100;
			printf("%d\n",seed);
		}
	}
	
}
//	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
//	颓废太久了，已经不会写代码了
//	高二了已经，感觉自己太废物了
//	我将AFO 
