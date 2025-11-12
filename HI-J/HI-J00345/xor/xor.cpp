#include <iostream>
#include <cstdio>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int l=1,r,xo,cnt=0;
	while(l<=n){
		xo=a[l];
		r=l;
		while(xo!=k&&r<=n){
			r++;
			xo=xo^a[r];
		}
		if(xo==k){
			cnt++;
			l=r;
		}
		l++;
	}
	cout << cnt;
	return 0;
} 
