#include<bits/stdc++.h>
using namespace std;
int n,m,g[109];
int dx[]={1,-1};
bool tmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",&g[i]);
	}
	int a=g[0];
	sort(g,g+n*m+1,tmp);
	int nowx=1,nowy=1,d=0;
	for(int i=1;i<=n*m;i++){
		if(g[i-1]==a)break;
		if(i%m==0){
			nowy++;
			d=i/m%2;
			continue;
		}
		nowx+=dx[d];
	}
	printf("%d %d\n",nowy,nowx);
	return 0;
}
