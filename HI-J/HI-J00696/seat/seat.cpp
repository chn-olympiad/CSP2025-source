#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,ans;
	cin >> n >> m >> x;
	ans=m*n;
	int a[1000];
	for(int i=0;i<m*n-1;i++){
		cin >> a[i];
	}
	for(int i=0;i<n*m-1;i++){
		if(x>a[i]){
			ans--;
		}
	}
	if(ans/m==0||ans==m){
		cout << 1 << " " << ans;
	}
	else{
		if(ans/m%2==1){
			cout << ans/m+1 << " " << n-(ans%m);
		}
		else{
			cout << ans/m+1 << " " << ans%m;
		}
	}
	return 0;
}
