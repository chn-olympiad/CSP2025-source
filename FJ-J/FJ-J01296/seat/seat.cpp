#include <bits/stdc++.h>
using namespace std;

bool kx(int &a , int &b){
	if(a<b){
		return a>b;
	}
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	int a[n*m+1];
	int b[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		b[i]=a[i];
	}
	sort(b+1,b+(n*m)+1,kx);
	int pos=0;
	for(int i=1;i<=n*m+1;i++){
		if(a[1]==b[i]){
			pos=i;
		}
	}
	int k=pos/n;
	int k2=pos%n;
	if(k2==0){
		if(k%2!=0){
			cout<<k<<" "<<n<<endl;
		}
		else{
			cout<<k<<" "<<1<<endl;
		}
	}
	else {
		int k3=k+1;
		if(k3%2!=0){
			cout<<k3<<" "<<k2<<endl;
		}
		else {
			cout<<k3<<" "<<n-k2+1<<endl;
		}
	}
	return 0;
}
