#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans=0;
bool vis[5010];
void bfs(int i,int num,int big,int num1){
	if(num1>=3 && num>big*2){
		ans=(ans+1)%998244353;
	}
	if(i>n) return ;
	if(vis[i]==0){
	    vis[i]=1;
	    bfs(i+1,num+a[i],max(big,a[i]),num1+1);
	    vis[i]=0;
    }
	bfs(i+1,num,big,num1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	memset(vis,0,sizeof(vis));
	bfs(1,0,0,0);
	cout<<ans;
	return 0;
}
