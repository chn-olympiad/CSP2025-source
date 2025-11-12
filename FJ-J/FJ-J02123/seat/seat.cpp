#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[110],tmp,s[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	sum=n*m;
	for(int i=1;i<=sum;i++){
		scanf("%d",&a[i]);
	}
	tmp=a[1];
	stable_sort(a+1,a+sum+1);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				s[i][j]=a[sum];
				if(a[sum]==tmp){
					printf("%d %d",j,i);
					return 0;
				}
				sum--;
			}
		}else{
			for(int i=n;i>=1;i--){
				s[i][j]=a[sum];
				if(a[sum]==tmp){
					printf("%d %d",j,i);
					return 0;
				}
				sum--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
