#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
    int n,m,k,u[10005],v[10005],w[10005],c[10005],a[10005][10005],min;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
    	cin >>u[i]>>v[i]>>w[i];
	
	for(int j=1;j<=k;j++){
		cin >> c[j] >> a[i][j];
	}
}
    if(n=1){
				min = w[n+1];
			}
			else{
				min=w[n];
			}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
         if(k!=0){
			min = w[n]+c[j]+a[i][j];
		}
			cout << min;
		}
	}
	return 0;
} 
 
