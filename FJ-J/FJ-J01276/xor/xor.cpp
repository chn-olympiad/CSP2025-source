#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int a[N];
int visited[N];
int n,k,zdz=0;
void dfs(int wz,int z,int len){
	if(z==k&&len>zdz){
		zdz=len;
		return;
	}
	visited[wz]=1;
	if(wz+1<=n&&visited[wz+1]==0){
		dfs(wz+1,z^a[wz],len+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		memset(visited,0,sizeof(visited));
		dfs(i,a[i],1);
	}
	cout<<zdz<<endl;
	return 0;
}
/*
4 2
2 1 0 3
*/
