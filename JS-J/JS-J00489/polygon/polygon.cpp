#include<bits/stdc++.h>
using namespace std;
int n,a[10010],ans,b[10010];
bool vis[10010];
void dfs(int k,int dep,int s,int last){
/*	for(int i=1;i<=n;i++){
		if(vis[i]) cout<<a[i]<<" ";
	}cout<<"\n";
*/	if(dep>=k){
		if(s>a[last]*2){
			ans++;//cout<<s<<" "<<last<<"   ans!!!!!!!    \n";
			if(ans>=998244353)
				ans-=998244353;
		}
		return ;
	}
	for(int i=last+1;i<=n;i++){
		vis[i]=1;//cout<<last<<"     reach   \n";
		dfs(k,dep+1,s+a[i],i);
		vis[i]=0;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
/*	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
*/	for(int i=3;i<=n;i++) dfs(i,0,0,0);
	cout<<ans<<"\n";
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

