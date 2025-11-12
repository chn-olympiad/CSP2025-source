#include<bits/stdc++.h>
using namespace std;
int j,n,m,a[105],x,c,r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		j=n*m-i+1;
		if(a[i]==x){
			c=(j-1)/n+1;
			r=j-n*(c-1);
			if(c%2==0){
				r=n+1-r;
			}
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
}
