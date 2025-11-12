#include<bits/stdc++.h>
using namespace std;
int map_[1005][1005],ans[10][1005],minn=100000000,mp[1005];
int n,m,k;
void dfs(int place,int step,int point){
	if(step==n-1){
		minn=min(minn,point);
		cout<<step<<" "<<point<<endl;
		return ;
	}
	cout<<step<<" "<<point<<endl;
	for (int i=1;i<=n;i++){
		if(!mp[i]){
			mp[i]=1;
			dfs(i,step+1,point+map_[place][i]);
			mp[i]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for (int i=0;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		map_[x][y]=z;
		map_[y][x]=z;
	}
	int c;
	cin>>c;
	for (int i=0;i<n;i++){
		cin>>ans[0][i];
	}
	for (int i=1;i<k;i++){
		int c;
		cin>>c;
		for (int j=0;j<n;j++){
			int cover;
			cin>>cover;
			ans[i][j]=min(cover,ans[i-1][j]);
		}
	}
	int cnt=0;
	for (int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(map_[i+1][j+1]==0){
				map_[i+1][j+1]=ans[k-1][j]+ans[k-1][i];
			}
			else{
				map_[i+1][j+1]=min(ans[k-1][j]+ans[k-1][i],map_[i+1][j+1]);
			}
			map_[j+1][i+1]=map_[i+1][j+1];
		}
	}
	for (int i=1;i<=n;i++){
		mp[i]=1;
		dfs(i,0,0);
		mp[i]=0;
		cout<<endl;
	}
	cout<<minn;
	return 0;
}
