#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,k=1;
	bool doru=1,con=0;
	scanf("%d%d",&n,&m);
	int a[m*n+1]={},c[n][m]={};
	scanf("%d",&b);
	for(int i=2;i<=m*n;i++){
		scanf("%d",&a[i]);
	}
	a[1]=b;
	sort(a+1,a+m*n,cmp);
	for(int j=1;j<=m;j++){
		if(con){
			break;
		}
		doru=(j%2)==1;
		if(doru){
			for(int i=1;i<=n;i++){
				c[i][j]=a[k++];
				if(c[i][j]==b){
					printf("%d %d",j,i);
					con=1;
					break;
				}
					
			}
		}else{
			for(int i=n;i>=1;i--){
				c[i][j]=a[k++];
				if(c[i][j]==b){
					printf("%d %d",j,i);
					con=1;
					break;
				}
					
			}
		}
	}
	return 0;
}
