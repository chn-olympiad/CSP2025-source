#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int x=1,y=1;
    int a1;
    cin>>n>>m>>a1;
    for(int i=1;i<n*m;i++){
    	int k;
    	cin>>k;
    	if(k>a1){
    		if(x%2==1){
    			y++;
    			if(y>n){
    				y=n;
    				x++;
				}
			}else{
				y--;
				if(y<1){
					y=1;
					x++;
				}
			}
		}
	}
	cout<<x<<' '<<y;
	
	return 0;
} 
