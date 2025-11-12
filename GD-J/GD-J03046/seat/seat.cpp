#include<bits/stdc++.h>
using namespace std;
int a[11][11],n,m,t,aa,x;
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	cin>>aa;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>aa) t++;
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(t>0){
					t--;
					continue;
				}
				cout<<i<<" "<<j;
				return 0;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(t>0){
					t--;
					continue;
				}
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}

