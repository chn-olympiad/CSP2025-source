#include<bits/stdc++.h>
using namespace std;
int n,m,b,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			b=a[i];
		}
	}
	sort(a+1,a+1+n*m);
	int c=1,r=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==b){
			cout<<c<<" "<<r;
			return 0;
		}
		if(c%2==1){
			r++;
		}else{
			r--;
		}
		if(r>n){
			c++;
			r=n;
		}
		if(r<1){
			c++;
			r=1;
		}
	}
	return 0;
} 
