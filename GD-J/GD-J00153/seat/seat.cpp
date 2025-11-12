#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1001],l,r,sum;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	cin>>a[1];
	for(int i=2;i<=l;i++){
		cin>>a[i];
		if(a[i]>a[1])r++;
	}r++;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				sum++;
				if(sum==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				sum++;
				if(sum==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
}
