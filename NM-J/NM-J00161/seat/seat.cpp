#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,z;
int a[1000];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;++i){
		cin >> a[i];
		a[i]=100-a[i];
	}
	x = a[1];
	y=n;
	z=m;
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;++i){
		if(a[i]==x){
			if(i%n==0){
				n=i/y;
				if(n%2==1){
					m=y;
				}
				else{
					m=1;
				}
			}
			else{
				n=i/y+1;
				if(n%2==1){
					m=i%m;
				}
				else{
					m=z-i%m+1;
				}
			}
		}
	}
	cout << n << " " << m;
	return 0;
}
