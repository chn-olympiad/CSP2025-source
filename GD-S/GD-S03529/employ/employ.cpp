#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int s[N];
int c[N];
int p[N];
bool used[N];
int n,m;
int res;
void dfs(int k){
    if(k>n){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]==0) ++cnt;
            else if(c[p[i]]<=cnt) ++cnt;
        }
        res+=(cnt<=n-m);
        return;
    }
    for(int i=1;i<=n;i++){
        if(used[i]) continue;
        p[k]=i;
        used[i]=1;
        dfs(k+1);
        used[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%1d",&s[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    if(m==n){
    	bool bz=1;
    	for(int i=1;i<=n;i++) 
    		if(s[i]==0) bz=0;
    	for(int i=1;i<=n;i++)
    		if(c[i]==0) bz=0;
    	if(bz){
    		int res=1;
    		for(int i=1;i<=n;i++)
    			res=1ll*res*i%mod;
    		cout<<res;
		}
		else cout<<0;
		return 0;
	} 
    dfs(1);
    cout<<res;
}
