#include <bits/stdc++.h> 
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	for(int i=1;i<=n*m;i++){
		if(a[i]<a[i+1]){
			int y=0;
			y=a[i];
			a[i]=a[i+1];
			a[i+1]=y;
		}
	}
	int  o;
	for(int i=1;i<=n*m;i++){
		if(r==a[i]){
			o=i;
			break;
		}
	}
	if(o%n==0){
		cout<<o/n<<' '<<1;
		return 0;
	}
	if(o<=n){
		cout<<1<<' '<<o/n;
		return 0;
	}
	if(o/n%2!=0){
		cout<<o/n+1<<' '<<n-o%n+1;
		return 0;
	}
	cout<<o/n<<' '<<(o-n)%n+1; 
	return 0;
}
