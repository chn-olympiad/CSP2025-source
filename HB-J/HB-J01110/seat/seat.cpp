#include<bits/stdc++.h>
using namespace std;
long long n,m,w,xa=1,book=0,ya=0;
long long a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	w=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		
		if(xa%2==0&&ya-1>=1){
			ya--;
		}
		
		else if(xa%2!=0&&ya+1<=n) {
			ya++;
		}
		else{
			xa++;
		}
		if(a[i]==w){
			cout<<xa<<" "<<ya;
			break;
		}
	}
	
	return 0;
}

