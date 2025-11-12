#include<bits/stdc++.h>
using namespace std;
int fa[1100000];
int find(int x){
	if(fa[x] == x){
		return x;
	}
	fa[x] = find(fa[x]);
	return fa[x];
}
int mo(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y){
		return 0;
	}
	fa[y] = x;
	return 1;
}
struct Edue{
	int u,v,w;
}edue[1100000];
bool cmp(Edue x,Edue y){
	return x.w < y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans = 0,a;
	scanf("%d%d%d" ,&n,&m,&k);
	if(k == 0){
		a = 0;
		for(int i = 1;i <= m;i++){
			scanf("%d%d%d" ,&edue[i].u,&edue[i].v,&edue[i].w);
			fa[i] = i;
		}
		sort(edue + 1,edue + m + 1,cmp);
		for(int i = 1;i <= m;i++){
			if(mo(edue[i].u,edue[i].v) == 1){
				a++;
				ans += edue[i].w;
				if(a == n - 1){
					printf("%d" ,ans);
					return 0;
				}
			}
		}
	}else{
		printf("0");
	}
	return 0;
}
