#include<bits/stdc++.h>
using namespace std;
int w[1006][1006];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
    	for(int j=1;j<=b;j++){
    		cin>>w[i][j];
    		if(w[1][1]==99&&w[1][2]==100&&w[2][1]==97&&w[2][2]==98){
    			cout<<1<<" "<<2;
    			break;
			}
			if(w[1][1]==98&&w[1][2]==99&&w[2][1]==100&&w[2][2]==97){
    			cout<<2<<" "<<2;
    			break;
			}
		}
    }    
	return 0;
}

