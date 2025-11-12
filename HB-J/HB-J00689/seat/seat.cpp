#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[100005],f;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		scanf("%d",&a[i]);
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				f++;
				if(a[f]==ans){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				f++;
				if(a[f]==ans){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
