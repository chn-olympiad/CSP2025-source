#include<bits/stdc++.h>
using namespace std;
int s[15][15],a[105],x,y,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=0;i<x*y;i++){
		cin>>a[i];
	}
	ans=a[0];
	sort(a,a+x*y);
	for(int i=x*y-1;i>=0;i--){
		if(a[i]==ans){
			if(x==1){
				cout<<1<<" "<<i+1;
				return 0;
			}
			else if(y==1){
				cout<<i+1<<" "<<1; 
				return 0;
			}
		}
	}
}
