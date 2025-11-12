#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100001],b,f[501][501];
	cin>>n>>m;
	int c=0,r=0,g=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				g++;
				f[i][j]=a[g];
			}else{
				g++;
			}
			
		}
	}
	g=0;
	for(int i=1;i<=m;i++){
		for(int j=n;j>=1;j--){
			if(i%2==1){
				g++;
			}else{
				g++;
				f[i][j]=a[g];
			}
			
		}
	}
	int s=0;
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]==b){
				cout<<j<<" "<<i;
				return 0;
			}
		}
		
	}
	cout<<c<<" "<<r;
	return 0;
}

