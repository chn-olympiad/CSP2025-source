#include<bits/stdc++.h>
using namespace std;
const int N=1005;
long long n,m,a[N],b[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n*m);
	long long k=2*n,l;
	for(int i=n*m;i>=1;i--){
		if(b[i]==a[1]){
			l=i;
			break;
		}
	}
	l=n*m-l+1;
	long long z=l%k,z1=l/k;
	if(z>n){
		z1=z1*2+2;
		z=z-n;
		z=n-z+1;
		cout<<z1<<" "<<z;
	}
	else{
		z1=z1*2+1;
		cout<<z1<<" "<<z;
	}
	return 0;
} 

