#include <bits/stdc++.h>
using namespace std;
int m,n,a,k,qmq=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=0;i<m*n-1;i++){
		cin>>a;
		if(a>k){
			qmq++;
		}
	}
	if(qmq>=9*n+1 && qmq<=10*n){
		
		k=10;
		
	}else if(qmq>=8*n+1 && qmq<=9*n){
		
		k=9;
		
	}else if(qmq>=7*n+1 && qmq<=8*n){
		
		k=8;
		
	}else if(qmq>=6*n+1 && qmq<=7*n){
		
		k=7;
		
	}else if(qmq>=5*n+1 && qmq<=6*n){
		
		k=6;
		
	}else if(qmq>=4*n+1 && qmq<=5*n){
		
		k=5;
		
	}else if(qmq>=3*n+1 && qmq<=4*n){
		
		k=4;
		
	}else if(qmq>=2*n+1 && qmq<=3*n){
		
		k=3;
		
	}else if(qmq>=n+1 && qmq<=2*n){
		
		k=2;
		
	}else if(qmq>=1 && qmq<=n){
		
		k=1;
		
	}
	if(k%2==0){
		cout<<k<<" "<<k*n-qmq+1;
	}else{
		cout<<k<<" "<<qmq-(k-1)*n ;
	}
	return 0;
} 