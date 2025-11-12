#include<bits/stdc++.h>
using namespace std;
int n,m,a1;
int x,y;
int a[101];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		scanf("%d",&a[i]);
	a1=a[0];
	sort(a,a+n*m,cmp);
//	for(int i=0;i<n*m;i++)
//		printf("%d ",a[i]);
	printf("\na1: %d\n",a1);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
//					printf("%d i: %d j: %d case1\n",(i-1)*n+(n-j)-1,i,j);
				if(a[(i-1)*n+(n-j+1)-1]==a1){
//					printf("%d %dcase1\n",i*n+j-1,j-1);
					x=i;y=j;
					goto print;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
//					printf("%d i: %d j: %d case2\n",(i-1)*n+j-1,i,j);
				if(a[(i-1)*n+j-1]==a1){
//					printf("%d %d case2\n",a[i*n+j-1],j-1);
					x=i;y=j;
					goto print;
				}
			}
		}
	}
	print:
		 printf("%d %d",x,y);
		 return 0;
}
