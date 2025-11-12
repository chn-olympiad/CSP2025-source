#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],i,j,k,r,mx;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	mx = 1;
	cin >> n >> m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			k++;
			cin >> a[k];
			if(a[k] > a[1]){
				mx++;
			}
		}
	}
	r = ceil(mx*1.0/m);
	if(r == 1){
		cout << 1 << " " << mx;
		return 0;
	}
	if(r % 2){
		cout << r << " " << mx-(r-1)*m;
	}
	else{
		cout << r << " " << m-mx+(r-1)*m+1;
	}
	return 0;
}
