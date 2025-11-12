#include<bits/stdc++.h>
using namespace std;
int n,cnt;
vector<int>v;
void dfs(int maxn,int nn,int i){
	if(i==n){
		if((maxn*2)<nn){
			cnt++;
		}
	}
	else{
		dfs(max(maxn,v[i]),nn+v[i],i+1);
		dfs(maxn,nn,i+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	dfs(0,0,0);
	cout<<cnt;
	return 0;
}
