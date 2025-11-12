#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int c[15][15];
int d[550];
int dj=0,flag=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int fj_j00676=n;
	if (n>m){
		n=m;
		m=fj_j00676;
	}
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
			dj++;
			d[dj]=a[i][j];
			
		}
	}
	sort(d+1,d+1+dj);
	flag=dj;
	for (int i=1;i<=m;i++){
		
	
		if (i%2==1){
			for (int j=1;j<=n;j++){
				c[j][i]=d[flag];
				flag--;
			}
		}
		if (i%2==0){
			for (int j=n;j>=1;j--){
				c[j][i]=d[flag];
				flag--;
			}
		}
	}
	for(int i=1;i<m;i++){
		for (int j=1;j<=n+1;j++){
			if (c[i][j]==a[1][1]){
				cout<<j<<' '<<i;
				return 0;
			}
			
		}
		
	}
}
