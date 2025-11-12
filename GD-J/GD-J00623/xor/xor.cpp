#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,maxm=(1<<20)+10;
int n,k,a[maxn],vis[maxm],pre;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(vis,-1,sizeof(vis));
    cin>>n>>k;
	int ans=0;
    for(int i=1;i<=n;++i){
    	cin>>a[i];
    	pre^=a[i];
    	if(pre==k||((vis[pre^k]==ans)&&a[i]!=0)) ++ans,pre=0;
    	else vis[pre]=ans;
	}
	cout<<ans;
    return 0;
}
