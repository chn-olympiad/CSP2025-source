#include<bits/stdc++.h>
using namespace std;
int a[20],n,m,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[i*n-j+1]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 
