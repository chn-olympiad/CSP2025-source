#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int c[9];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int b=0;
	cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=k;j++){
    		cin>>a[i][j];	
		}
		b=n+m+k+3;
    }
	cout<<b;
	return 0;
}