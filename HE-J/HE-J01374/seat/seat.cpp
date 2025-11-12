#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000],b[11][11];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++){
   	cin>>a[i];
   }
   int x=a[1];
   sort(a+1,a+1+n*m);
   int bj=n*m;
   for(int j=1;j<=m;j++){
   	if(j%2==1){
   		for(int i=1;i<=n;i++){
   			b[i][j]=a[bj];
   			bj--;
		   }
	   }else if(j%2==0){
	   	for(int i=n;i>=1;i--){
	   		b[i][j]=a[bj];
	   		bj--;
		   }
	   }
   }
   for(int i=1;i<=n;i++){
   	for(int j=1;j<=n;j++){
   		if(b[i][j]==x){
   			cout<<j<<" "<<i;
   			return 0;
		   }
	   }
   }
	return 0;
}
