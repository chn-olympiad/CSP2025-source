#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000005][5],b[100005][15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	int ans=1000005,ans1=1000005;
	if(k==0){
		for(int i=1;i<=m;i++){
			if(a[i][3]<=ans){
				ans=a[i][3];
			}
		}
		for(int i=1;i<=m;i++){
			if(a[i][3]==ans){
				a[i][3]=1000005;
			}
		}
		for(int i=1;i<=m;i++){
			if(a[i][3]<=ans1){
				ans1=a[i][3];
			}
		}
		int sum=ans+ans1;
		printf("%d",sum);
	}
	else{
		int sum1=ans+ans1+k;
		printf("%d",sum1);
	}
	return 0;
}
