#include<bits/stdc++.h>
using namespace std;
long long a[101];
int b[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	int p=n*m;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[j][i]=a[p];
				if(a[p]==k){
					cout<<i<<" "<<j;
					return 0;
				}
				p-=1;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[j][i]=a[p];
				if(a[p]==k){
					cout<<i<<" "<<j;
					return 0;
				}
				p-=1;
			}
		} 
	}
	return 0;
}