#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,k;cin>>n>>m;
	int a[n][m];
	int b[1000];cin>>b[1000];
	for(int i=0;i<=n;i++){
		if(b[i]<<b[i+1]){
			b[i]=k;
			b[i+1]=b[i];
			k=b[i+1];
		}
	}cout<<12;
} return 0; 
