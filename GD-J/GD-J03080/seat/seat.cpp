#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],b[110],a1;
int r=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a,a+n*m+1);
	int s=1;
	for(int i=n*m;i>=1;i--){
		b[s]=a[i];
		s++;
	}
	for(int i=1;i<=n*m;i++){
		int c;
		if(i%n==0){
			c=i/n;
		}
		else{
			c=i/n+1;
		}
		if((i-1)%n==0){
			r=r;
		}
		else if(c%2==1){
			r=r+1;
		}
		else if(c%2==0){
			r=r-1;
		}
		if(b[i]==a1){
			cout<<c<<' '<<r<<endl;
		}
	}
	return 0;
}
