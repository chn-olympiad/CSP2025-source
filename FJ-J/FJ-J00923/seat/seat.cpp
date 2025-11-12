#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[N];
	for(int i=0;i<1e8;i++){
		a[i]=INT_MAX;
	}
	a[0]=-1;
	for(int i=1;i<=n*m;i++){
		int p;
		cin>>p;
		a[i]=p;
	}
	int r=a[1];
	int k=n*m;
	sort(a+1,a+k+1);
	for(int i=1;i<=k;i++){
		if(a[i]==r){
			r=k-i+1;
			break;	
		}
	}
	int x,y;
	if(r%n!=0){
		y=r/n+1;
	}
	else{
		y=r/n;
	}
	if(y%2==1){
		if(r%n==0){
			x=n;	
		}
		else{
			x=r%n;
		}
	}
	else{
		x=n-r%n+1;
	}
	cout<<y<<' '<<x;
}
