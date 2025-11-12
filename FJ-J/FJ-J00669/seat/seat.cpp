#include<bits/stdc++.h>
using namespace std;
int w,n,m,x,y,b[110],c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	c=b[1];
    sort(b+1,b+n*m+1);
    for(int i=1;i<=n*m;i++){
    	if(b[i]==c){
    		w=i;
		}
	}
    w=n*m-w+1;
	x=1;y=1;
	while(1){
		if(x==1){
			while(x!=n){
				x++;
				w--;
				if(w==1){
					cout<<y<<' '<<x;
					return 0; 
				} 
			}
		}
		else if(x==n){
			while(x!=1){
				x--;
				w--;
				if(w==1){
					cout<<y<<' '<<x;
					return 0; 
				} 
			} 
		}
		y++;
		w--;
	    if(w==1){
				cout<<y<<' '<<x;
				return 0; 
		}
	}
}
