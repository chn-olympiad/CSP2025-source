#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++) cin>>a[i];
	int z = a[1],x = 1,y = 1;//x––y¡– 
	for(int i = 2;i <= n*m;i++){
		if(a[i]>z){
			if(y%2==0){
			    if(x==1){
				    y++;
			    }
			    if(x>1){
			    	x--;
			    }
		    }else{
			    if(x==n){
				    y++;
			    }
			    if(x<n){
				    x++;
			    }
		    }
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
