#include <bits/stdc++.h>
using namespace std;
int cj[105] = {0};
int z[10][10];
int main(){
    //freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int numr = n*m;
	for(int i=0;i<numr;i++){
		cin>>cj[i];
	} 
	int xm = cj[0];
	int dx = 0,dy = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		    if(i%2==1){
			    z[n-1-j][i] = cj[j];
		    }else{
			    z[j][i] = cj[j];
			}
			if(cj[j]== xm){
				dx = j+1;dy = i;
				continue;
			}
	    }
	}
	cout<<dy<<" "<<dx;
	return 0; 
}

