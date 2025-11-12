#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,id;
int a[10005];
int mo(int x,int mod){
	if(x%mod==0){
		return mod;
	}else{
		return x%mod;
	}
}
int chu(int x,int mod){
	if(x%mod==0){
		return x/mod-1;
	}return x/mod;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int nw=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==nw){
			id=i;
			break;
		}
	}
	id=n*m-id+1;
	int aa=ceil((double)id/n);
	int bb;
	if(aa%2==1){
		bb=mo(id,n);
	}else{
		bb=n-mo(id,n)+1;
	}
	cout<<aa<<" "<<bb;
	 
}
