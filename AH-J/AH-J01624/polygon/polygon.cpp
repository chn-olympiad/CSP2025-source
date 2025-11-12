#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],f[21][101][2001];
long long dfs(long long x,long long y,long long z){
	if(x>n){
		if(z>y*2&&z!=0&&y!=-1){
			return 1;
		}
		return 0;
	}
	if(f[x][y][z]!=-1){
		return f[x][y][z];
	}
	return f[x][y][z]=dfs(x+1,max(y,a[x]),z+a[x])+dfs(x+1,y,z);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(f,-1,sizeof(f));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,-1,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
