#include<iostream>
using namespace std;
int n,total;
const int N=5010;
int num[N];bool vis[N];
void dfs(int r,int sum,int maxn,int k){
	if(r>=3&&sum>maxn*2){
		total++;
	}
	if(k==n+1)return;
	dfs(r,sum,maxn,k+1);
	if(!vis[k]){	
		vis[k]=true;
		dfs(r+1,sum+num[k],max(maxn,num[k]),k+1);
		vis[k]=false;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	dfs(0,0,0,1);
	cout<<total<<"\n";
	return 0;
}
