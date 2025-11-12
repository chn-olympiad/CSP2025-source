#include <bits/stdc++.h>
using namespace std;

int n,m,a[105],e,x;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	e = n * m;
	for(int i=0;i<e;i++){
		cin>>a[i];
	}
	x = a[0];
	sort(a,a+e);
	for(int i=0;i<e;i++){
		if(a[i]==x){
			int t = e-i;
			int c;
			if(t%n==0){
				c = t/n;
				cout<<c<<" ";
				if(c%2==1)cout<<n;
				else cout<<1;
			}else{
				int r;
				c = t/n+1;
				r = t%n; 
				cout<<c<<" ";
				if(c%2==1){
					cout<<r;
				}else{
					cout<<n-r+1;
				}
			}
		}
	}
	return 0;
}
