#include<bits/stdc++.h>
using namespace std;

int a[100005][5],v[100005][5];
int n,ans=0;

void dfs(int x,int y){
	if(x>n){
		int sum=0;
		int f=0,s=0,t=0;
		//cout<<"F:";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
//				cout<<v[i][j]<<' ';
				if(v[i][j]==1) {
					if((j==1&&f<n/2)||(j==2&&s<n/2)||(j==3&&t<n/2)){
						sum+=a[i][j];
						if(j==1) f++;
						if(j==2) s++;
						if(j==3) t++;
					}
					else return;
				}
			}
//			cout<<'\n';
		}
		//cout<<"sum:"<<sum<<"\n";
		ans=max(sum,ans);
		return;
	}
	if(y>3){
		dfs(x+1,1);
		return;
	}
	if(y==1&&v[x][y+1]<=0&&v[x][y+2]<=0){
		v[x][y]=1;
		dfs(x,y+1);
	} 
	if(y==2&&v[x][y-1]<=0&&v[x][y+1]<=0){
		v[x][y]=1;
		dfs(x,y+1);
	} 
	if(y==3&&v[x][y-1]<=0&&v[x][y-2]<=0){
		v[x][y]=1;
		dfs(x,y+1);
	} 
	v[x][y]=0;
	dfs(x,y+1);
	v[x][y]=-1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,1);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
} 
