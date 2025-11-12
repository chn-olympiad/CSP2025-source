#include<bits/stdc++.h>
using namespace std;
int rc,sum,m,n,q,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	cin>>rc;
	for(int i=0;i<m*n-1;i++){
		cin>>q;
		if(q>rc){
			sum++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){if(sum==0){
				cout<<i<<" "<<j;
			}
			sum--;
			
		}
	}
	return 0;
} 
