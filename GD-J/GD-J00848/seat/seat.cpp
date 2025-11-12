#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,y,ans[105][105],k=1;
struct node{
	int bh;
	int z;
}a[1005];
bool cmp(node a,node b){
	return a.z>b.z;
}
//话说CCF今年的题太简单了吧 1<=n,m<=10 
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>a[i].z;
        a[i].bh=i;
	}
	sort(a+1,a+n*m+1,cmp); 
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				ans[j][i]=a[k].bh;
				k++;
			}
		}else{
			for(int j=m;j>=1;j--){
				ans[j][i]=a[k].bh;
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
        	if(ans[i][j]==1){
			    cout<<j<<" "<<i;
			}
		}
	} 
	return 0;
}
