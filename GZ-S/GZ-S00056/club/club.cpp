//GZ-S00056 遵义市第一中学 刘李学翀 
#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],j,i,sum=0;
void club(int x,int k,int a1,int a2,int a3){
	if(x>sum){
		sum=x;
	}
	if(k>n){
		return ;
	}
	if(a1<n/2){
		club(x+a[k][1],k+1,a1+1,a2,a3);
	}
	if(a2<n/2){
		club(x+a[k][2],k+1,a1,a2+1,a3);
	}
	if(a3<n/2){
		club(x+a[k][3],k+1,a1,a2,a3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(j=1;j<=t;j++){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		club(0,1,0,0,0);
		printf("%d\n",sum);
		sum=0;
	}
	fclose(stdin);
	fclose(stdout);
}
