#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int g[m][n];
	int q=0,w=m*n;
	int a[n*m];
	while(w--){
		cin>>a[q];q+=1;
	}int x=a[0];sort(a+1,a+w+1);
	for(int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			g[i][j]=a[i*j];
		}
	}for(int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if(x==g[i][j]){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	}

