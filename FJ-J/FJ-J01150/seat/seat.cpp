#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k,b[110][110],i,j,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}r=a[1];
	sort(a+1,a+n*m+1);
	for(i=1;i<=m;i++){
		if(i%2){
			for(j=1;j<=n;j++){
				k++;
				b[i][j]=a[k];
				if(a[k]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(j=n;j>=1;j--){
				k++;
				b[i][j]=a[k];
				if(a[k]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}return 0; 
}
