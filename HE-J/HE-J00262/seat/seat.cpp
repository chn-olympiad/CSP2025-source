#include <bits/stdc++.h>
using namespace std;
int a[101];
int main(int argc, char** argv) {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,c=1,r=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(i==n*m){
			cout<<m<<n;
			return 0;
		}
		int lt=1;
		for(int j=1;j<=n*m;j++){
			if(a[lt]<a[j]){
				lt=j;
			}
		}	
		if(lt==1){
			cout<<c<<' '<<r;
			return 0;
		}
		if(c%2==0&&r!=1){
			r--;
		}else if(c%2==1&&r!=n){
			r++;
		}else{
			c++;
		}
		a[lt]=-1;
	}
	return 0;
}
