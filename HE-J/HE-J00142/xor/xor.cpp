#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
bool f[10001][10001];
int ans=-1,cnt=0,z=0;
void dfs(int x,int y){
	if(x>n||y>n){
		return;
	}
	if(f[x][y]==1){
		cnt++;
		dfs(y+1,y+1);
	}
	else{
		dfs(x,y+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=a[i];
		if(cnt==k){
			f[i][i]=1;
		}
		for(int j=i+1;j<=n;j++){
			cnt^=a[j];
			if(cnt==k){
				f[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[i][j]==1){
				cnt=0;
				dfs(i,j);
				ans=max(ans,cnt);
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
