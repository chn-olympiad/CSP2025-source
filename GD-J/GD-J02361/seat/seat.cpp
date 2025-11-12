#include<bits/stdc++.h>
using namespace std;
int a[225],ans[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int t=0;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				ans[i][j]=a[++t];
			}
		}else{
			for(int j=n;j>0;j--){
				ans[i][j]=a[++t];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==r){
				printf("%d %d",i,j);
				break; 
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
