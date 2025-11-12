#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],nn,x=1,y=1,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	nn=n*m;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[nn]==r){
			cout<<y<<" "<<x;
			break;
		}
		if(y%2==0){
			if(x==1){
				y=y+1;
			}
			else{
				x=x-1;
			}
		}
		else{
			if(x==n){
				y=y+1;
			}
			else{
				x=x+1;
			}
		}
		nn=nn-1;
	}
	return 0;
}
