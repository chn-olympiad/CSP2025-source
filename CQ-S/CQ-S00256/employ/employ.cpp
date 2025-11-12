#include <bits/stdc++.h>
using namespace std;
int n,m,b[30],c[30],ex[30],ansn=0;
string fs;
void dfs(int num,int ans,int lef){
	//printf("%d %d %d\n",num,ans,lef);
	if(num==n+1){
		if(ans>=m){
			ansn++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		
		if(b[i]==1)continue;
		b[i]=1;
		if(fs[num-1]=='0'){
			dfs(num+1,ans,lef+1);
		}
		else if(lef>c[i]){
			dfs(num+1,ans,lef+1);
		}
		else{
			dfs(num+1,ans+1,lef);
		}
		b[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>fs;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ansn;
	return 0;

}

