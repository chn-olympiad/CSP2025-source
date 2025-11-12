#include<bits/stdc++.h>
using namespace std;
int n,m,c,g=1,a[110],b[110][110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[g];
				g++;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[g];
				g++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==c){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
