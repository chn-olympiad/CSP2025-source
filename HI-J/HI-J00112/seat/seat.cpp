#include<bits/stdc++.h>
using namespace std;
long long int m,n;
double x[10010][10010],y[10010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){ 
		cin>>y[i];
	}
	int a=y[1],k=n*m+1;
	sort(y+1,y+n*m+1);
	
	
	for(int i=1;i<=m;i++){
		
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				x[j][i]=y[k--]; 
				if(y[k]==a){
					cout<<i<<" "<<j;
				}
			}	
		}else{
			for(int j=n;j>=1;j--){
				x[j][i]=y[k--];
				if(y[k]==a){
					cout<<i<<" "<<j;
				}
			}
		}
		
	}
	
	return 0;
}
