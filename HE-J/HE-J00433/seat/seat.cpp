#include<bits/stdc++.h> 
using namespace std;
int m,n,a[110],c[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b=1,r;
	for(int i=1;i<=m*n;i++){
		cin>>a[b];
		if(b==1) r=a[b];
		b++;
	}
	b--;
	sort(a+1,a+b+1);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				c[i][j]=a[b];
				if(a[b]==r)cout<<i<<" "<<j;
				b--;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				c[i][j]=a[b];
				if(a[b]==r)cout<<i<<" "<<j;
				b--;
			}
		}
	}
	return 0;
}
