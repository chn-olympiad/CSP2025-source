#include<bits/stdc++.h>
#define let long long
#define rt return
using namespace std;
let n,m,k,
	a,b,c,
	A,
	mp[1010][1010];
struct node{
	let x,sum;
};
vector<node> vt[10010];
void solve(){

	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(let i = 1;i<=m;i++){
		cin>>a>>b>>c;
		vt[a].push_back({b,c});
		vt[b].push_back({a,c});
	}
	for(let i = 1;i<=k;i++){
		cin>>mp[i][0];
		for(let j = 1;j<=n;j++){
			cin>>mp[i][j];
			if(i == j)mp[i][j] = 0;
		} 
		if(mp[i][0] == 0) A++;
	}
	if(A == k){
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	rt 0;
}

