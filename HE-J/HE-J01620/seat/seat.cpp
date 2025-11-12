#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N],n,m;
int main() {
	freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
    cout<<a[i];
    if(a[i]<a[i+1]){
    	a[i]=a[i+1];
    	cout<<a[i]<<" ";
	}
	}

	return 0;
}


