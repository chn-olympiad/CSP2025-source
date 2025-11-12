#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+1+n*m);
	int cnt=n*m;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[cnt]==ans){
					cout<<i<<" "<<j;
					return 0;
				}	
				cnt--;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(a[cnt]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt--;
			}
		}
	}
	return 0;
}