#include<bits/stdc++.h>
using namespace std;
int n,m,a1,ans;
int a[150];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			ans=i;
			break;
		}
	}
	int z=ans/n,zl=ans%(2*n);
	if(ans%n==0){
		z--;
	}
	z++;
	if(0<zl&&zl<=n){
		cout<<z<<" "<<zl;
	}
	if(zl==0||(n<zl&&zl<=2*n)){
		cout<<z<<" ";
		if(zl==0){
			cout<<1;
		}
		else{
			cout<<2*n-zl+1;
		}
	}
	return 0;
}