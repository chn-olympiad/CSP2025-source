#include "bits/stdc++.h"
#define LL long long
#define VT vector
#define lst(type,size) new type[size]
using namespace std;
int n,m,as,ast;
int sco[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&sco[i]);
	as=sco[1];
	sort(sco+1,sco+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(sco[i]==as){
			ast=i;
			break;
		}
	}
	int alst,ah=0;
	if(ast%n==0)alst = ast/n;
	else alst = ast/n+1;
	if(alst%2==0){
		for(int i=alst*n;i>(alst-1)*n;i--){
			ah++;
			if(sco[i]==ast)break;
		}
	}else{
		for(int i=alst*n;i>(alst-1)*n;i--){
			if(sco[i]==as){
				ah=i%n;
				if(ah==0)ah=n;
				break;
			}
		}
	}
	printf("%d %d",alst,ah);
}