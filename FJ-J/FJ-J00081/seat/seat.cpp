#include<bits/stdc++.h>
using namespace std;

int n,m;
int b[150];
int r;
int x,y,k = 1,p;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n*m;i++){
		scanf("%d",&b[i]);
	}
	r = b[1];
	sort(b+1,b+n*m+1,cmp);
	x = 1,y = 1,p = 1;
	while(x<=n && y<=m){
		if(b[p] == r){
			printf("%d %d",y,x);
			return 0;
		}
		if(x == n && k == 1){
			k = -1;
			y++;
		}else if(x == 1 && k == -1){
			k = 1;
			y++;
		}else{
			x+=k;
		}
		p++;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
