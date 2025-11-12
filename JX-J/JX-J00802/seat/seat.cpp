#include <bits/stdc++.h>
using namespace std;
int x,y,a;
int s[105];
int w[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&x,&y,&a);
	s[0]=a;
	for(int i=1;i<x*y;i++){
		scanf("%d",&s[i]);
	}
	for(int i=0;i<x*y;i++){
		for(int j=0;j<x*y-1;j++){
			if(s[j]<s[j+1]) swap(s[j],s[j+1]);
		}
	}
	for(int i=1;i<=y;i++){
		for(int j=1;j<=x;j++){
			if(i%2==1) w[i][j]=s[x*(i-1)+j];
			else w[i][j]=s[x*(i-1)+x-j+1];
		}
	}
	for(int i=1;i<=y;i++){
		for(int j=1;j<=x;j++){
			if(w[i][j]==a) printf("%d %d",i,j);
			return 0;
		}
	}
	return 0;
}
