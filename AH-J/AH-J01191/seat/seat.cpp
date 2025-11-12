#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			ans=(n*m)-i+1;
			break;
		}
	}
	c=(ans-1)/m+1;
	if(c%2==1) r=(ans-1)%n+1;
	else r=n-((ans-1)%n);
	cout<<c<<' '<<r;
	return 0;
}

