#include<bits/stdc++.h>
using namespace std;
int c[2100000];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,m,R,P,C,r;
	cin >> n >> m;
	for(int i = 0; i < n*m;i++){
		cin >> c[i];
	}
	R = c[0];
	sort(c,c+n*m);
	//for(int j = 0;j < n*m;j++)
	//	cout << c[j] << " ";
	for(int j = 0; j < n*m;j++){
		
		if(c[j]==R){
			P=j;
			
			break; 
		}
	}
	if(P<=n){
		C = n;
		r = 1;
	}
	else if((P/n)%2){
		C = n-(P-n*(P/n));
		r = P/n;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
	
	cout << r << " " << C;
	cout << " " << P;
	return 0;
}

