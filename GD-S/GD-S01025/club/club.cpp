#include <iostream>
using namespace std;

int t,n,as[100007][3],ans=-1,hn;

void dfs(int a,int c1,int c2,int c3,int ind){
	if(c1>hn || c2>hn || c3>hn) return;
	if(a>ans) ans=a;
	for(int i=ind;i<=n;i++){
		dfs(a+as[ind][0],c1+1,c2,c3,i+1);
		dfs(a+as[ind][1],c1,c2+1,c3,i+1);
		dfs(a+as[ind][2],c1,c2,c3+1,i+1);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		ans=-1;
		cin>>n;
		hn=n/2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>as[i][j];
			}
		}
		dfs(0,0,0,0,1);
		cout<<ans<<endl;
	}
	return 0;
}
