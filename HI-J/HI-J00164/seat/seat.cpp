#include<bits/stdc++.h>
using namespace std;
int a[1100];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1],nm=n*m;
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i]==ans){
			c=(i/m)+(i%m);
			r=i%n;
			if(r==0){
				r=n;
			}
			if(c%2==0){
				r=n-r+1;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
