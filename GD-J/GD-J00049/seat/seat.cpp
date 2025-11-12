#include<bits/stdc++.h>
using namespace std;
int n, m, a[200], k, kk, mp[50][50];
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>a[++k];
		}
	}
	int t=a[1], nl=1;
	sort(a+1, a+n*m+1, cmp);
	while(true){
		for(int i=1; i<=n; i++){
			kk++;
			if(a[kk]==t){
				cout<<nl<<' '<<i;
				return 0;
			}
			mp[nl][i]=a[kk];
		}
		nl++;
		if(nl>m){
			break;
		}
		for(int i=n; i>=1; i--){
			kk++;
			if(a[kk]==t){
				cout<<nl<<' '<<i;
				return 0;
			}
			mp[nl][i]=a[kk];
		}
		nl++;
		if(nl>m){
			break;
		}
	}
	return 0;
}
