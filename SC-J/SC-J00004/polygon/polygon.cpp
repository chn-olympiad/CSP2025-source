#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a(100000);
bool visited[100000]={};
long long cnt=0,ans=0,xuan=1;
void dfs(int step,int xuan) {
	if(step>=3){
		for(int i=1;i<=n;i++){
			if(visited[i]==0) continue;
			if(cnt-a[i]<=a[i]) {
				
				break;
			}
			if(i==n){
				ans++;
				
			}
		}
	}
	for(int i=xuan;i<=n;i++){
		if(1){
			cnt+=a[i];
			visited[i]=1;
			dfs(step+1,i+1);
			cnt-=a[i];
			visited[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1);
	cout<<ans;
}