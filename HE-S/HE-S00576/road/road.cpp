#include <bits/stdc++.h>
using namespace std;
int n,m,k; 
int a[1000005];
int b[10];
int c[1000000005];
int u,v,w;
int main(){
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
    	for (int j=1;j<=i+1;j++){
    		cin >> u >> v >> w;	
		}
	}
	for (int i=1;i<=k;i++){
		 for (int j=1;j<=i+m+1;j++){
		 	cin >> c[i];
		 }
	}
	int x=0,y=0;
	for (int i=1;i<m+1;i++){
		for (int j=1;j<m+k+1;j++){
			x=min(x,a[i]);
			y+=x;
		}
	}
	cout << y;
	return 0;
	//±£´æÊ±½â×¢ÊÍ 
}
