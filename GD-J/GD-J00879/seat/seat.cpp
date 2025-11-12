#include<bits/stdc++.h>
using namespace std;
int mp[105][105];
int sum[200005];
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)cin>>sum[i];
	int ans=sum[1];
	sort(sum+1,sum+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){ 
			if(i%2!=0){
				if(sum[i*n-n+j]==ans){
					cout<<i<<" "<<j;
					return 0;
				}	
			}else{
				if(sum[i*n-j+1]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
