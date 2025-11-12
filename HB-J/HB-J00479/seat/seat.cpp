#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum1,ans,xr,b[15][15],c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.in","w",stdout);
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
		}
	sum1=n*m;
	for(int i=1;i<=sum1;i++){
		cin>>a[i];
		}
		xr=a[1];
		c=n*m;
		sort(a+1,a+1+sum1);
		for(int i=1;i<=n;i++){	
			if(i%2==1){
				for(int j=1;j<=m;j++){
					b[i][j]=a[c];
					c--;
					}
			}else{
				for(int j=m;j>=1;j--){			
					b[i][j]=a[c];
					c--;
			}
		}
	}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(b[i][j]==xr){
						cout<<i<<" "<<j;
						return 0;
					}
				}
			}
	return 0;
}
