#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int l=n*m;
	
	for(int i=1;i<=l;i++){
		scanf("%d",&a[i]);
	}
	int a1num=a[1];
	sort(a+1,a+l+1,cmp);
	
	int cnt=1,tx=1,ty=1;//n*m
	while(cnt<=l&&ty<=m){
		for(;tx<=n;tx++){
			b[tx][ty]=a[cnt++];
		}
		tx--;//>n
		ty++;
		if(ty>m)break;
		for(;tx>=1;tx--){
			b[tx][ty]=a[cnt++];
		}
		tx++;
		ty++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==a1num){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
}
