#include<bits/stdc++.h>

using namespace std;
int a[5011];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m,ans;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
		if(i==1){
			ans=a[i];
		}
	}
	int c,r;
	sort(a+1,a+1+sum);
	reverse(a+1,a+1+sum);
	for(int i=1;i<=sum;i++){
		if(a[i]==ans){
			c=(i-1)/n+1;
			if(c%2==1){
				r=(i-1)%n+1;
		}
		else if(c%2==0){
			r=n-(i-(c-1)*n)+1;
		}
	}
}
	cout<<c<<" "<<r;
	return 0;
}
