#include<bits/stdc++.h>
using namespace std;
int f[110],c[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,z;
	cin >> n >> m;
	t=n*m;
	for(int i=1; i<=t; i++){
		cin >> f[i];
	}
	z=f[1];
	sort(f+1,f+t+1);
	for(int i=1; i<=t; i++){
		c[t-i+1]=f[i];
		if(c[t-i+1]==z){
			z=t-i+1;
		}
	}
	if(z%m==0){
		if(z/n%2==0){
			cout << z/n << ' ' << '1';
		}else{
			cout << z/n << ' ' << n;
		}
	}else{
		if((z/n+1)%2==0){
			cout << z/n+1 << ' ' << n-(z-(z/n*n))+1;
		}else{
			cout << z/n+1 << ' ' << z-z/n*n;
		}
	}
	return 0;
}