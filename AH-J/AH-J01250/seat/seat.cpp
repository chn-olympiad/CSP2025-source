#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int c=(n+1)*(m+1);
	int a[c+1];
	int xy[n+1][m+1];
	for(int h=1;h<=n*m;h++){
		scanf(" %d",&a[h]);	
	}
	int man=a[1];
	for(int h=n*m-1;h>=1;h--){
		for(int p=1;p<=n*m-1;p++){
			if(a[p+1]>a[p]){
				int tmp=0;
				tmp=a[p+1];
				a[p+1]=a[p];
				a[p]=tmp;
			}
		}
	}
	int top=1;
	int y=1;
	for(int x=1;x<=n;x++){
		for(;y<=m&&y>=1;){
			xy[x][y]=a[top];
			top++;
			if(xy[x][y]==man){
				printf("%d %d",x,y);
				return 0;
			}
			if(x%2==1){
				y++;
			}
			else
			{
				y--;
			}
		}
		if(y==0){
			y++;
		}
		if(y>m){
			y=m;
		}
	}	
	return 0;
}
