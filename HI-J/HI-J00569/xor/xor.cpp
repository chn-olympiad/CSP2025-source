#include<bits/stdc++.h>
using namespace std;
int n,k,g[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool op=1,A=1,B=1,C=1;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>g[i];
		if(g[i]!=1){
			A=false;
		}
	}
	int x=0,y=0;
	if(A){
		for(int i=2;i<=n;i+=2){
				int pq=1,qp=1,o;
				for(int j=1;j<=i;j++){
					pq=pq*j;
					qp=qp*(n-j+1); 
			    }
				o=qp/pq;
				y+=o;
		}
		cout<<y;
		return 0;
	} 
	return 0;
} 
