#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ans,e;
bool sha(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+1+n*m,sha);
	int d=1;
	for(int j=1;j<=m;j++){
		if(j%2>0){
			for(int k=1;k<=n;k++){
				if(a[d]==ans){
					cout<<j<<" "<<k;
					e+=1;
					break;
				}
				d++;
			}
		}else if(j%2==0){
			for(int h=n;h>=1;h--){
				if(e>0){
					break;
				}
				if(a[d]==ans){
					cout<<j<<" "<<h;
					break;
				}
				d++;
			}
		}
	}
	return 0;
}
