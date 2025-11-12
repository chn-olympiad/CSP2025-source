#include <bits/stdc++.h>
using namespace std;
int a[15][15],n,m,r,b[105];
bool df(int x,int y){
	return x>y;
}	
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	r=b[1];
	int t=m*n;
    sort(b+1,b+1+t,df);
    int v=1;
    for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(b[v]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				v++;
			}
		}	
		else{
			for(int j=1;j<=n;j++){
				if(b[v]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				v++;
			}
		}	
	}	
    return 0;
}
