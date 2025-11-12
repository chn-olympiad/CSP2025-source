#include<bits/stdc++.h>
using namespace std;
int n;
int a[5002];
long long an;
void dfs(int s,int mx,int x,int g){
	if(x>n){
		if(g>=3&&s>mx*2){
			an++;
		}
		return;
	}
	dfs(s+a[x],max(mx,a[x]),x+1,g+1);
	dfs(s,mx,x+1,g);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	dfs(0,0,1,0);
	cout <<an%998244353;
	return 0;
}
