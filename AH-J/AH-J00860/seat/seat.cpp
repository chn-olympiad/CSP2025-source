#include "bits/stdc++.h"
using namespace std;
#define int long long
int a[10001];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int ans=a[1];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+(n*m)+1,cmp);
	//for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
	//cout<<endl;
	int s=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[s++]==ans){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[s++]==ans){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
