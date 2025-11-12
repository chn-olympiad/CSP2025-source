#include<cstdio>

int main(){
	std::freopen("seat.in","r",stdin);
	std::freopen("seat.out","w",stdout);
	int x,y;
	int a[20][20];
	scanf("%d %d",&x,&y);
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int sum;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			if(a[i][j]>a[1][1]) sum++;
		}
	}
	printf("%d %d",sum/x+1,sum%x+1);
	return 0;
}
