#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long ans;
int a[50005],b[50005];
bool vis[50005];
void dfs(int num,long long sum,int maxx,int step){
	if(num>=3&&sum>maxx*2){
		ans++;
	}
	for(int i=step;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			b[num]=a[i];
			dfs(num+1,sum+a[i],max(maxx,a[i]),i);
			vis[i]=false;
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
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
}
