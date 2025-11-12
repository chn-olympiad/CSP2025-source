#include<bits/stdc++.h>
using namespace std;
const int mod=998244353; 
int n,m;
int c;
char s[101];
int a[101];
int p[101];
int mem[101][101][101];
int con(int x,int y){
	int up=1;
	for(int i=0;i<x;i++){
		up=(up*(y-i))%mod; 
	}
	int down=1;
	for(int i=1;i<=y;i++){
		down=(down*i)%mod;
	}
	return up/down;
}

int dfs(int x,int y,int z){
//	cout<<x<<" "<<y<<" "<<z<<"\n";
	//前x人，录用y人(1) ,z人不录用或放弃 
	if(y>=m){
		//共n人，已经录用y人
		//还能录用(c-y)人
		//还有(n-x)人等待面试 
		//n-x选c-y 
		return con(n-x,c-y);
	}
	if(x==n){
		return 0;
	}
	if(mem[x][y][z]!=-1){
		return mem[x][y][z];
	}
	else{
		x++;
		int ans;
		if(z>=p[x]){
			ans = (dfs(x,y,z+1)%mod+dfs(x,y+1,z+1)%mod)%mod;
		} 
		else{
			ans = (dfs(x,y,z+1)%mod+dfs(x,y+1,z)%mod)%mod;
		}
		mem[z][y][z]=ans;
		return ans;
	}
}

int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	memset(mem,-1,sizeof mem);
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			c++;
		}
	} 
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	cout<<dfs(0,0,0);
	
	return 0;
} 
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
