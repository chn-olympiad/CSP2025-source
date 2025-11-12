#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15],c[10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,s=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
    sort(a+1,a+n*m+1);
    int z=1;
    for(int i=n*m;i>=1;i--){
    	c[z]=a[i];
    	z++;
	}
    for(int j=1;j<=m;j+=2){
    	for(int i=1;i<=n;i++){
    		b[i][j]=c[s];
    		s++;
    		if((s-1)%n==0){
    			s=s+n;
			}
		}
	}
	s=n+1;
	for(int j=2;j<=m;j+=2){
    	for(int i=n;i>=1;i--){
    		b[i][j]=c[s];
    		s++;
    		if((s-1)%n==0){
    			s=s+n;
			}
		}
	}
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(b[i][j]==r){
    			cout<<j<<" "<<i;
    			return 0;
			}
		}
	}
	cout<<1;
	return 0;
}
