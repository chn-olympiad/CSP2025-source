#include<bits/stdc++.h>
using namespace std;
long long a[10015][10015];
bool flag[10015];
int x1[10015];
int n,m,k;
void dfs(int step,int en,int k){
	flag[step]=false;
	if(step==en){
		return ;
	}
	long long mini=INT_MAX;
	for(int i=1;i<=n;i++){
		if(a[step][i]>0&&a[i][en]==0&&flag[i]){
			dfs(i,en,step);
			mini=min(mini,a[i][en]+a[step][i]);
		}else if(a[step][i]>0&&a[i][en]>0&&flag[i]){
			mini=min(mini,a[i][en]+a[step][i]);
		}
	}
	if(mini!=INT_MAX&&mini!=0){
		a[step][en]=mini;
		a[en][step]=a[step][en];		
	}
	flag[step]=true;
	return ;
}
int main(){
	freopen("road2.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=-1;
		}
		flag[i]=true;
	}
	for(int i=1;i<=n;i++){
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[x][y]=z;
			a[y][x]=z;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				cout<<0<<" ";
				continue;
			}
			if(a[i][j]==-1) dfs(i,j,i);			
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			scanf("%d",&x1[j]);
		}
		int sum=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(j!=k){
					if(a[j][k]>x1[j]+x1[k]){
						sum+=(x1[j]+x1[k])-a[j][k];
					}
				}
			}
		}
		if(sum<x){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(j!=k){
						if(a[j][k]>x1[j]+x1[k]){
							a[j][k]=x1[j]+x1[k];
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum+=a[i][j];
		}
	}
	printf("%d",sum/2);
	return 0;
}
