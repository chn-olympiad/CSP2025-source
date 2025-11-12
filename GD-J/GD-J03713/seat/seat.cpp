#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100+23];
int ran;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])	ran++;
	}
	ran++;
	int tot=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				tot++;
				if(tot==ran){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				tot++;
				if(tot==ran){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
