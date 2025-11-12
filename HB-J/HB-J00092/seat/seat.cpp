#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200],z,x=0,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopem("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	z=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(y%2==1)x++;
		else if(y%2==0)x--;
		if(x>n){
			x--;
			y++;
		}else if(x<1){
			x++;
			y++;
		}
		if(a[i]==z){
			cout<<y<<' '<<x;
			return 0;
		}
	}
}
