#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=1,r=1,a[102],s;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s=a[1];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(r==n+1&&c%2!=0){
			r=n;
			c++;
		}else{
			if(r==0&&c%2==0){
				r=1;
				c++;
			}
		}
		if(c%2==1){	
			if(a[i]==s){
				cout<<c<<" "<<r;
				return 0;
			}
			r++;
		}else{
			if(a[i]==s){
				cout<<c<<" "<<r;
				return 0;
			}
			r--;
		}
	}
	return 0;
}


