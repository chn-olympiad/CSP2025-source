#include<bits/stdc++.h>
using namespace std;
int a[11][11];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen(seat.in,"r",std.in);
    freopen(seat.out,"w",std.out);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>a[i][j];
		}
	}
	int s=a[1][1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s==a[i][j]){
                if(j%2==1)cout<<i<<" "<<j;
                else cout<<i<<" "<<m-j+1;
			}
		}
	}
	return 0;
}

