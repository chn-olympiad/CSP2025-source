#include <bits/stdc++.h>
using namespace std;
int n,m,res,Day[507],lx[507];
char ch[507];
int mark[507];
void dfs(int depth){
	if(depth==n+1){
		int fq=0;
		for(int i=1; i<=n; ++i){
			if(fq>=lx[Day[i]]){
				++fq;
				continue;
			}
			if(ch[i]=='0') ++fq;
		}
		if(fq+m<=n) ++res;
		return;
	}
	for(int i=1; i<=n; ++i){
		if(mark[i]) continue;
		mark[i]=depth;
		Day[depth]=i;
		dfs(depth+1);
		mark[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; ++i){
    	cin>>ch[i];
	}
	for(int i=1; i<=n; ++i) cin>>lx[i];
	dfs(1);
	cout<<res;
	return 0;
}

