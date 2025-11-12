#include<bits/stdc++.h>
using namespace std;
int n,m,a[114],f,k,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	k=n*m;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[k]==f){
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[k]==f){
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
			}
		}
	}
	return 0;
}
