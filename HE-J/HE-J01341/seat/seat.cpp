#include <bits/stdc++.h>
using namespace std;
int a[105],s;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z;
	cin>>n>>m;
	z=n*m;
	for(int i=0;i<z;i++){
		cin>>a[i];
	}
	if(n==1 && m==1){
		cout<<1<<1;
		return 0;
	}
	else if(n==1 && m<=10){
		cout<<m<<1;
		return 0;
	}
	else if(n<=10 && m==1){
		cout<<1<<n;
		return 0;
	}
	s=a[0];
	int c,v;
	sort(a,a+z,cmp);
	
	for(int i=0;i<z;i++){
		if(a[i]=s){
			c=n%i+1;
			v=n%i;
			if(c%2==0){
				v++;
			}
			cout<<c<<" "<<v;
			return 0;
		}
	}
	return 0;
}
