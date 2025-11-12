#include<iostream>
#include<algorithm>
using namespace std;
int a[15][15],x[10000];
int main() {
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
    }
    int c=x[1];
    sort(x,x+n*m+1);
    for(int j=1;j<=m;j++){
    	if(j%2!=0){
	
	    	for(int i=1;i<=n;i++){
	    		a[i][j]=x[b];
	    		b--;
	        }
		}
		else{
			for(int i=n;i>0;i--){
				a[i][j]=x[b];
				b--;
			}
		}
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        	if(a[i][j]==c){
        		cout<<j<<" "<<i;
        	    return 0;
			}
		}
	}
	return 0;
}

