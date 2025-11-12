#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],q,b[1005][1005],p;
int main(){
	freopen("seat.in","r",stdin); freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	q=a[1];
	sort(a+1,a+n*m+1);
	p=0;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			if(i%2==1){
			b[i][j]=a[n*m-p];
			p++;
		   }
		   if(i%2==0){
		   	b[i][n-j+1]=a[n*m-p]; 
		   	p++;
		   }
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
		  if(b[i][j]==q)	
		  cout<<i<<" "<<j;
	
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}