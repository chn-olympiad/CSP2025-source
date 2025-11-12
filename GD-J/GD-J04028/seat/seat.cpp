#include <bits/stdc++.h>
using namespace std;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,w; 
bool iu(int x,int y){
	return y<x;
}
int a[1000];
int b[1000][1000]; 
int main(){
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		int x; 	
		cin>>x;
		 if(i==1){
			w=x; 	
		} 
		a[i]=x;
	}
	sort(a+1,a+m*n+2,iu);
	int o=1;
	int g=1,f=1;
	for(int i=1;i<=m;i++){ 
		for(int j=1;j<=n;j++){
			b[i][g]=a[o];
			o+=1;
			if(i%2==1){
				g++;
			}
			else if(i%2==0){
				g--;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(b[i][j]==w){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	
	return 0;
} 

