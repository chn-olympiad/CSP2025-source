#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int a,b=0;
}a[101];
bool cmp(node x,node y){
	return x.a>y.a;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	a[1].b=1;
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i].a);
	sort(a+1,a+n*m+1,cmp); 
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j].b==1){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[(i-1)*n+n-j+1].b==1){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

