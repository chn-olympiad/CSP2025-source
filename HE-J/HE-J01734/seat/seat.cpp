#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	long long ans[n+1][m+1];
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=m;j++){
			cin>>ans[i][j];
		}
	}
	long long a=ans[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2==1){
				if(ans[i][j]<ans[i+1][j]){
					ans[i][j]=max(ans[i][j],ans[i+1][j]);
				}
			}
			if(j%2==0){
				if(ans[i][j]>ans[i+1][j]){
					ans[i][j]=min(ans[i][j],ans[i+1][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==a){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	
	fclose(stdin);
    fclose(stdout);
	return 0;
}
