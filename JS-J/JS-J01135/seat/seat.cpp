#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,a[109];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	l=n*m+1;
	sort(&a[1],&a[n*m+1]);
	for(long long i=1;i<=m;i++){
		if(i%2==0){
			for(long long j=n;j>=1;j--){
				l--;
				if(a[l]==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else if(i%2==1){
			for(long long j=1;j<=n;j++){
				l--;
				if(a[l]==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
