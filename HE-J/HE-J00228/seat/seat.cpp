#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],k;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[j+i*n];
		}
	}k=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(a[i+j*n]==k){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	} 
	return 0;
}
