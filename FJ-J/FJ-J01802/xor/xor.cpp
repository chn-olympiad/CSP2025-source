#include <bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
ll n,k,a[500005],ans,b[500005];
bool qiu(ll x,ll y){
	int cnt=0;
	for(int j=x;j<=y;j++){
		cnt=cnt^a[j];
	}
	if(cnt==k){
		for(int i=x;i<=y;i++){
			if(b[i]==1) return false;	
		}
		for(int i=x;i<=y;i++){
			b[i]=1;
		}
		//cout<<x<<" "<<y<<endl; 
		return true;
	}
	return false;
}

void bfs(ll x,ll y){
	if(qiu(x,y)){
		ans++;
		return;
	}
	if(y==n) return;
	for(int i=y+1;i<=n;i++){
		bfs(x,i);
		
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) bfs(i,i);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

