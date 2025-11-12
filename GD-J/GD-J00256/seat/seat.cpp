#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],g=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) g++;
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				g--;
				if(g==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				g--;
				if(g==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

