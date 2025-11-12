#include<bits/stdc++.h>
using namespace std;
int n,m,a[1003],ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=m*n;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+s+1);
	for(int ii=s;ii>=1;ii--){
		if(a[ii]==ans){
			int i=s-ii+1;
			int c=(i-1)/n+1;
			int r=(i-1)%n+1;
			if(c%2==0)r=n-r+1;
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
}