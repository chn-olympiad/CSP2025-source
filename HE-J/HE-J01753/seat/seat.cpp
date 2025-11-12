#include<bits/stdc++.h>
using namespace std;
int n,m,a[150];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int sum=n*m,ans[15][15];
	for(int i=1;i<=sum;i++){
		scanf("%d",&a[i]);
	}
	int q=a[1];
	sort(a+1,a+sum+1,cmp);
	int h=sum%n,l=sum/n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				ans[i][j]=a[(i-1)*n+j];
			}else{
				ans[i][j]=a[(i-1)*n+(n-j+1)];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(ans[i][j]==q){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
}
