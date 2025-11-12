#include<bits/stdc++.h>
using namespace std;
int n,m,t,p=1;
int a[110];
int b[110][110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			t=a[i];
		}
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(p%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[c];
				if(a[c]==t){
					cout<<i<<" "<<j;
					return 0;
				}
				c--;
			}
			p++;
		}
		else{
			for(int k=n;k>=1;k--){
				b[i][k]=a[c];
				if(a[c]==t){
					cout<<i<<" "<<k;
					return 0;
				}
				c--;
			}
			p++;
		}
	}
	return 0;
}
