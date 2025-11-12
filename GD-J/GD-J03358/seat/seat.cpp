#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[100],n,m,b[100],f[100][100];
    cin>>n>>m;
    for(int i=0;i<=n*m;i++){
    	cin>>a[i];
    	b[0]=a[0];
	}
	
	if(n==m==1){
		cout<<"1 1";
		
	}
	return 0;
}
