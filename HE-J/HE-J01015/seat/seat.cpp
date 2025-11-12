#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[101],k,b[15][15],c=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a,a+m*n);
	for(int i=0;i<n*m;i++){
		c++;
		if(a[n*m-1-i]==k){
			break;
		}
	}
	cout<<(c-1)/n+1<<" ";
	if(((c-1)/n)%2==0){
		if(c%n!=0){
			cout<<c%n;
		}else{
			cout<<n;
		}
	}else{
		if(c%n!=0){
			cout<<n-(c%n);
		}else{
			cout<<1;
		}
	}
	return 0;
}
