#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],c,r,k,ans,s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			k++;
			for(int j=1;j<=n;j++){
				s++;
				if(a[s]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				s++;
				if(a[s]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
