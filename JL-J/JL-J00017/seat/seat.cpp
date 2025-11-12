#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,m,q;
    int a[m][n];
    int b[100001];
    cin>>m>>n;
    for(int i=1;i<=n+m;i++){
    	cin>>b[i];
    }
    q=b[0];
    sort(b,b+1);  
    for(int i=0;i<m;i--){
    	a[0][i]=b[i];
    }
    int y=1;
    while(n--){
    	if(y%2==1){
	    for(int i=0;i<m;i++){
	        a[y][i]=b[i*y];
	    }
	}
	if(i%2==0){
	    for(int i=0;i<m;i--){
	        a[y][i]=b[i*y];|
	        }
	      }
	y++;
	if(n<=0){
	    break;
	    }
	 }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    	    if(a[i][j]==q){
    	        cout<<a[i]<<" "<<j;
    	    }
    	}
    }
    return 0;
}
