#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],c,j=1,b[15][15],s;
int main(){
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=n*m;
	c=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=n+1;i++){
		//cout<<i<<j;
		if(j==1){
			if(j<1){
				j=1;
			}
			for(;j<=m;j++){
//				cout<<'>'<<j;
				b[i][j]=a[s];
				//cout<<b[i][j]<<i<<' '<<j<<endl;
				s--;
				if(b[i][j]==c){
					cout<<i<<' '<<j;
					return 0;
				}
			}
			if(j>m){
				j=m;
			}
		}else{
			for(;j>0;j=j-1){
				b[i][j]=a[s];
				//cout<<b[i][j]<<i<<' '<<j<<endl;
				s--;
				if(b[i][j]==c){
					cout<<i<<' '<<j;
					return 0;
				}
			}
			if(j<1){
				j=1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}