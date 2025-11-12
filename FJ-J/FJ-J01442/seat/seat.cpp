#include<bits/stdc++.h>
using namespace std;
const int N=15;
int b[N][N];
int a[105];
int n,m,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&r);
	a[1]=r;
	for(int i=2;i<=m*n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	bool fa=0;
	if(a[1]==r){
		printf("%d %d",x,y);
		return 0;
	}
	int v=1;
	while(true){
		v++;
		if(x<n&&fa==0){
			x++;
		}
		else if(x==n&&fa==0){
			y++;
			fa=1;
		}
		else if(x==1&&fa==1){
			y++;
			fa=0;
		}
		else if(x>1&&fa==1){
			x--;
		}
		if(a[v]==r){
			printf("%d %d",y,x);
			break;
		}
	} 
	return 0;
} 
