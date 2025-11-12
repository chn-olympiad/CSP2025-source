#include <bits/stdc++.h>
using namespace std;

int a[106];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,T;
	cin >> n >> m;
	for(int i=1; i<=n*m; i++)
		cin >> a[i];
	int R=a[1];
	int o=n*m-1;
	while(o){
		for(int i=1; i<=n*m; i++){
			if(a[i]<a[i+1]){
				int t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}	
		o-=1;
	}
	for(int i=1; i<=n*m; i++){
		if(a[i] == R){
			T=i;
			break;
		}
	}
	
	if(T<=n)
		cout << 1 << " "<< T;
	else{
		if(T%n==0){
			r=T/n;
			if(r%2==0)
				c=1;
			else
				c=n;
		}
		else{
			r=T/n+1;
			if(r%2==0)
				c=n-T%n+1;
			else
				c=T%n;
			}
		cout << r << " "<< c;
	}
	return 0;
}
