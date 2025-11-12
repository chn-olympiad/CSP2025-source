#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],d[1005][1005];


void init(){
        for(int i=0;i<=n;i++){
		    for(int j=1;j<=m;i++){
			    if(j==m){
				    if(a[i][j]<a[i+1][1])swap(a[i][j],a[i+1][j]);
			    }
			    else{
				    if(a[i][j]<a[i][j+1])swap(a[i][j],a[i][j+1]);
			    }
		    }
	    }
    
}


int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
    int n,m;
	cin>>n>>m;
	int sum = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	    cin>>a[i];
    }9*
    int X==a[1][1];
    init();
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++){
				d[i][j]=a[i][j];
			}
			else{
				for(int i=n;i>=1;i--){
					d[i][j]=a[i-1][j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(X==d[i][j]){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	
		  
	}
}
