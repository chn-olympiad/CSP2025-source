#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	for(int i=1;i<=n*m;i++){
		b[a[i]]++;
	}

	int nx;
	int mx;
	int x=1;
	for(int i=100;i>=1;i--){
		if(i==r){
			break;
		}
		if(b[i]!=0){
			x++;
		}
	}
	if(x%n!=0){
		mx=x/n+1;
	}else{
		mx=x/n;
	}
	if(mx%2==1){
		if(x%n!=0){
			nx=x%n;	
		}else{
			nx=n;
		}	
	}else{
		if(x%n!=0){
			nx=(n+1)-(x%n);
		}else{
			nx=1;
		}
			
	}
	cout<<mx<<" "<<nx;
	return 0;
}
