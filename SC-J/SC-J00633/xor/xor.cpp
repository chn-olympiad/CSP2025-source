#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500005];
int ans=0;
bool check(int x,int y){
	int q=a[x];
	for(int i=x+1;i<=y;i++){
		q=q^a[i];
	}
	if(q==k){
		return true;
	}
		return false;
}
void dfs(int x,int y){
	int c=0;
	if(check(x,y)){
		ans++;
		c=1;
	}
	if(y==n){
		return;
	}
	if(c==1){
		dfs(y+1,y+1);
	}
	else{
		dfs(x,y+1);
	}
	return;
	
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<ans;
	
	return 0;
}