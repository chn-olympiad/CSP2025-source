#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
string s;
int n,m,k,g;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) k=a[i];
	}
	sort(a+1,a+n*m+1);
	g=n*m+1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				g--;
				if(a[g]==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				g--;
				if(a[g]==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
