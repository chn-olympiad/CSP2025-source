#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans,a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	ans=a[1];
	for(int i=1;i<=sum;i++){
		for(int j=i+1;j<=sum;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=sum;i++){
		if(a[i]==ans){
			long long x,y;
			if(i%n==0){
				y=i/n;
				x=n;
				cout<<y<<" "<<x;
				break;
			}
			else if(i%n){
				y=i/n+1;
				if(y%2){
					x=i-n*(y-1);
					cout<<y<<" "<<x; 
					break;
				}
				else{
					x=n*y-i+1;
					cout<<y<<" "<<x;
					break;
				}
			}
		}
	}
return 0;
}
