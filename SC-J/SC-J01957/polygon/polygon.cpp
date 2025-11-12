#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+7,mod=998244353;
int n,a[MAXN],s[MAXN],vis[MAXN];
long long ans,je[MAXN],z; 
void dfs(int c,int x,int f,int h){
    if(x==c&&h>f){
        z++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(c+1,x,max(f,a[i]*2),h+a[i]);
            vis[i]=0;
        }
    }
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
	je[0]=1;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
		je[i]=je[i-1]*i;
    }
    for(int i=3;i<=n;i++){
		z=0;
		dfs(0,i,0,0);
		ans+=z/je[i];
    }
    cout<<ans%mod;
    return 0;
}