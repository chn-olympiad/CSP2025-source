#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],a[505],ans;
string s;
void dfs(int x,int y){
	if(x==n){
		int sum=0,x=0;
		for(int i=1;i<=n;i++){
			if(x<c[a[i]]){
				if(s[i-1]=='0'){
					x++;
				}
				else{
					sum++;
				}
			}
			else{
				x++;
			}
		}
		if(sum>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!((y>>(i-1))&1)){
			a[x+1]=i;
			dfs(x+1,y^(1<<(i-1)));
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}