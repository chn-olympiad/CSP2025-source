#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,a[N],x;
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			x=n*m-i+1;
			break;
		}
	}
	int d=(x/(2*n))+(x%(2*n)!=0); 
	d=d*2-1;
	x=(x-1)%(2*n)+1;
	if(x<=n){
		cout<<d<<' '<<x;
	}else{
		cout<<d+1<<' '<<2*n-x+1;
	}
	return 0;
} 
