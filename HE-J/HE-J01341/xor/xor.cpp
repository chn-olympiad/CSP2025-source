#include <bits/stdc++.h>
using namespace std;
int a[105],s;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,z;
	cin>>n>>m;
	z=n*m;
	for(int i=0;i<z;i++){
		cin>>a[i];
	}
	s=a[0];
	int c,v;
	sort(a,a+z,cmp);
	for(int i=0;i<z;i++){
		if(a[i]=s){
			if(i>n){
				c=i%n+1;
				v=i%n;
				if(c%2==0){
					v++;
				}
				cout<<c<<" "<<v;
				return 0;
			}
			else if(i<=n){
				cout<<1<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
