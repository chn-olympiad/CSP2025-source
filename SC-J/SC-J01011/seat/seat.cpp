#include<bits/stdc++.h>
#define int long long
using namespace std;
int fdh[105],ans[15][15];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,x,y;
	cin>>n>>m;
	y=m*n;
	for(int i=1;i<=m*n;i++) cin>>fdh[i];
	x=fdh[1];
	sort(fdh+1,fdh+1+m*n);
	for(int i=1;i<=m/2;i++){
		for(int j=1;j<=n;j++){
			ans[j][i*2-1]=fdh[y];
			y--;
		}
		for(int j=n;j>=1;j--){
			ans[j][i*2]=fdh[y];
			y--;
		}
	}
	if(m%2==1)
		for(int i=1;i<=n;i++){
			ans[i][m]=fdh[y];
			y--;
		} 
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout<<ans[i][j]<<" ";
		cout<<endl;
	}	*/
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(ans[j][i]==x){
				cout<<i<<" "<<j;
				break;
			}
	return 0;
} 