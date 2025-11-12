#include <bits/stdc++.h>
using namespace std;
int n,m,k1[100],c,k=0,d=0,a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		k=1;
		for(int j=n;j<=n-i;j--){
			k=j*k;
			cout<<k<<' ';
		}
		c=1;
		for(int j=i;j<1;j++){
			c=j*c;
		}
		k=k/c;
		d+=k;
	}
	cout<<k;
	return 0;
}
