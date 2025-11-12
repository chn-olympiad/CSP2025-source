#include<bits/stdc++.h>
using namespace std;
short a[15][15],n,m,b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=m*n;
	for(int i=1;i<=c;i++){
		cin>>b[i];
	}
	
	int r=b[1];
	sort(b+1,b+m*n+1);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=b[c];
				c--;
				if(a[i][j]==r){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				a[i][j]=b[c];
				c--;
				if(a[i][j]==r){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
		}
		
	}
	return 0;
}
