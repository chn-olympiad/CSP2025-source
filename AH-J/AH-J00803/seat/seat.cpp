#include<bits/stdc++.h>
using namespace std;
int a[150];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	int d=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[d]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
				d++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[d]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
				d++;
			}
		}
	}
    return 0;
}
