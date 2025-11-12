#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15],f=1,cnt;
bool cow(int a,int b){
	if(a>b)return true;
	return false;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+n*m+1,cow);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
			    b[j][i]=a[f];
			    f++;
	        }
		}else{
			for(int j=m;j>=1;j--){
			    b[j][i]=a[f];
		    	f++;
	        }
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==cnt){
				cout<<i<<" "<<j;
				f=b[i][j];
				break; 
			} 
	    }
	    if(f==cnt){
				break; 
			} 
    }
	return 0;
}

