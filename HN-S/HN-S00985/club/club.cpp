#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans;
int a[N][5];
void dfs(int len,int sum,int x,int y,int z){
	if(len>n){
		ans=max(ans,sum);
		return ;
	}
	if(x<n/2) dfs(len+1,sum+a[len][1],x+1,y,z);
	if(y<n/2) dfs(len+1,sum+a[len][2],x,y+1,z);
	if(z<n/2) dfs(len+1,sum+a[len][3],x,y,z+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0,0,0,0);	
		cout<<ans<<endl;
	}
	return 0;
} 
