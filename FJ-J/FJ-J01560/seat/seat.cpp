#include<bits/stdc++.h>
using namespace std;
	freopen("seat.in""r"stdin);
	freopen("seat.out""w"stdout);
	int main(){
		int a,b,max=0;
		int n[1000][1000];
		cin>>a>>b;
			for(int i=1;i<=a*b;i++){
				cin>>n[i];
			
			for(int i=1;i<=a;i++){
				for(int j=1;j<=b;j++){
					if(n[a][b]>=max){
						max=n[a][b];
						cout<<n[a][b];
						break;
					}	
				}
				}
			}
			
		return 0;
	}
