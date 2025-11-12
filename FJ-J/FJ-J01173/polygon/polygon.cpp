#include<bits/stdc++.h> 
using namespace std;
int n,sum,b[5005],c[5005],maxb[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		c[i]=c[i-1]+b[i];
		maxb[i][i]=b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i+j<=n){
				maxb[i][i+j]=max(maxb[i][i+j-1],maxb[i+j-1][i+j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j>=i,j<=n;j++){
			if(2*maxb[i][j]<c[j]-c[i]){
				sum++;
			}
		}
	}
	printf("%d",sum);
	return 0;
}
