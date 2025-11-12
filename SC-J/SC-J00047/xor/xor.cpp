#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,k,ans;
bool vis[N];
void dfs(int x,int sum){
	if(x>n){	ans=max(ans,sum);return;}
	if(!vis[x]){
		vis[x]=1;int temp=a[x];bool flag=0;
		if(a[x]==k){
			dfs(x+1,sum+1);ans++;vis[x]=0;
		}
		for(int i=x+1;i<=n;i++){
			temp^=a[i];if(temp==k){
				temp=i;ans++;flag=1;break;
			}if(flag){
				for(int i=x+1;i<=temp;i++) vis[i]=1;
				dfs(temp+1,sum+1);
				for(int i=x;i<=temp;i++) vis[i]=1;
			}else dfs(x+1,sum);
		}
	}else{
		dfs(x+1,sum);
	}
}
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];if(a[i]==1) cnt++;
	}
	if(cnt==n && k==0) cout<<n/2;
	else{
		dfs(1,0);cout<<ans;
	}return 0;
}