#include<bits/stdc++.h>
using namespace std;
long long a[15][15],n,m,c[105],you,ji,jj,js=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;js=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	you=c[1];
	sort(c+1,c+n*m+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[j][i]=c[js];
			js--;
		}
		i++;
		for(int j=n;j>=1;j--){
			a[j][i]=c[js];
			js--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(you==a[i][j]){
				ji=i;
				jj=j;
			}
		}
	}
	cout<<jj<<' '<<ji;
	return 0;
}
