#include <bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,a[110];
int main(){
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];	
	}
			for(int i=0;i<n*m;i++){
				if(a[0]<a[i]&&x<n)
				x++;
		        else if(a[0]<a[i]&&x==n&&y<m){
		    	    for(int j=n;j==1;j--){
		    	    	if(a[0]<a[i])
		    		x--;
				    }
					y++;	
			   }
			}	
	cout<<y<<" "<<x;
	return 0;
}
