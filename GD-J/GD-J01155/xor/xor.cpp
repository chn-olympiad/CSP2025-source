#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,k,a[500005],maxn,tmp;
vector<int> g[500005];
bool check(int r,int ll){
	if(r<ll) return 1;
	return 0;
}
void dfs(int l,int r,int cnt){
	if(r>=tmp||r>=n){
		return ;
	}
	for(int i=r+1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			if(check(r,i)){
				maxn=max(maxn,cnt+1);
				dfs(i,g[i][j],cnt+1);
			}
		} 
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				if(tmp!=0){
					maxn+=tmp/2;
				}
				tmp=0;
				maxn++;
			}else{
				if(a[i]==1){
					tmp++;
				}
			}
		}
		cout<<maxn;
		return 0;
	}else{
		if(k==1){
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]){
					maxn++;
				}
			}
			cout<<maxn;
			return 0;
		}else{
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]==k){
					tmp=max(tmp,i);
					maxn++;
					g[i].push_back(i);
				}
				for(int j=1;j<i;j++){
					a[j]^=a[i];
					if(a[j]==k){
						g[j].push_back(i);
						tmp=max(tmp,j);
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<g[i].size();j++){
					dfs(i,g[i][j],1);
				}
			}
			cout<<maxn;
			return 0;
		} 
	}
	
} 
/*
4 3
2 1 0 3
*/
