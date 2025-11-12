#include<bits/stdc++.h>
using namespace std;
const int K=1e3+5,N=15,M=15;
int a[K],mp[N][M];
bool cmp(int x, int y){
     return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
       cin>>a[i];
   }
   int t;
      t=a[1];
       sort(a+1,a+1+n*m,cmp);
       int cnt=1;
    for(int i=1;i<=m;i++){
		if(i%2==1){
		   for(int j=1;j<=m;j++){
			   mp[j][i]=a[cnt++];
			   }
		 }
		else{
			for(int j=n;j>=1;j--){
			   mp[j][i]=a[cnt++];
			   }
			
			}
		}
		
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==t){
				cout<<j<<" "<<i;
				return 0;
			}
		}
}
    return 0;
}
