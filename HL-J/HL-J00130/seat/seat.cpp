#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	int ar=a[1],z;
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(ar==a[i]){
			z=i;
			break;
		}
	}
	if(z<=n){
		cout<<"1 "<<z;
	}
	else{
		int xr=z/n+1;
		int yr=z%n;
		if(xr%2==0){
			cout<<xr<<" "<<n-(yr-1);
		}
		else cout<<xr<<" "<<yr;
	}
	return 0;
} 
