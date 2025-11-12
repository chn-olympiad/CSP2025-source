#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans;
bool b[5001];
void dfs(int index,int k,int start,long long sum,int maxn,int jum){
	if(index>k&&sum>2*maxn){
		ans++;
		return;
	}
	for(int i=start;i<=n;i+=jum){
		if(b[i]==1) continue;
		b[i]=1;
		dfs(index+1,k,start+1,sum+a[i],max(maxn,a[i]),jum+1);
		b[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++){
		dfs(1,i,1,0,0,1);
	}
	cout<<ans;
	return 0;
}
