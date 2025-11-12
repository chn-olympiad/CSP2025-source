#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long r; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a+0,a+n*m);
	

	for(int i=n*m;i>=0;i--){
		if(a[i]==r){
			r=n*m-i;
			break;
		}
	}
	int l;
	l=r/n;
	if(r!=n){
		cout<<l+1<<" ";
	}else{
		cout<<l<<" ";
	}
	if(l%2==0||l==0){
		if(r%n==0){
			cout<<n;
		}else{
			cout<<r%n;
		}
	}else{
		if(r%n==0){
			cout<<n;
		}else{
			cout<<n-(r%n)+1;
		}
	}
	return 0;
} 
