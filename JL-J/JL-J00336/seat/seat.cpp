#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int len,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n*m;i++) cin >> a[i];
	len=a[0];
	sum=n*m;
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++) {
		if(a[i]==len){
			for(int k=1;k<sum/n;k++)
				if(i>=sum/k)	cout << k << ' '<< sum/n-k;
		}
	}
	return 0;
}
