#include<bits/stdc++.h>
using namespace std;
int a[10010],b[10010][10010];
bool down(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans,sum=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	ans=a[0];
	sort(a,a+(n*m),down);
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				if(a[sum]==ans){
					cout<<i<<' '<<j;
				}
				b[i][j]=a[sum];
				sum++;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(a[sum]==ans){
					cout<<i<<' '<<j;
				}
				b[i][j]=a[sum];
				sum++;
			}
		}
	}
	return 0;
}
