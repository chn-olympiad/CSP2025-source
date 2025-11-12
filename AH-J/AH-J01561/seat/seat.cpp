#include <bits/stdc++.h>
using namespace std;
int n,m,a[150],b[12][12],c[150000],d[180],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//cin
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	int seat1=a[1];
	for(int i=180;i>=1;i--){
		if(c[i]==1){
			cnt++;
			d[cnt]=i;	
		}
	}for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			b[i][j]=d[j+(i-1)*n];
		}
	}
	for(int i=2;i<=m;i+=2){
		for(int j=n;j>=1;j--){
			b[i][j]=d[n-j+(i-1)*n+1];
		}
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==seat1){
			cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}

