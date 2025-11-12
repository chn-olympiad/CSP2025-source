#include<bits/stdc++.h>
#define let long long


#define rt return
using namespace std;
let n,mp[1000100],ans,a;
void dfs(let id,let cnt,let sum,let maxn){
	if(id == n+1){
		if(cnt>=3&&sum>maxn*2)ans++;
		rt;
	} 
	dfs(id+1,cnt,sum,maxn);
	dfs(id+1,cnt+1,sum+mp[id],max(maxn,mp[id]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(let i = 1;i<=n;i++){cin>>mp[i];if(mp[i] == 1)a++;}
	if(a == n){
		let sum = 0;
		for(let i = 3;i<=n;i++)sum+=((n+n-i+1)*i/2)/((1+i)*i/2);
		rt 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	rt 0;
}
