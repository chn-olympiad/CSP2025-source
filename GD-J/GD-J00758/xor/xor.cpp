#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,a[N];
map<int,map<int,int>> f;
int dfs(int i,int s){
	if(i>n) return 0;
	if(f[i][s]) return f[i][s];
	if(s==k){
		f[i][s]=max(dfs(i+1,a[i+1]),dfs(i+1,-1))+1;
		return f[i][s];
	}else if(s==-1){
		f[i][s]=max(dfs(i+1,a[i+1]),dfs(i+1,-1));
		return f[i][s];
	}else{
		f[i][s]=dfs(i+1,s^a[i+1]);
		return f[i][s];
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(0,-1);
	return 0;
}
