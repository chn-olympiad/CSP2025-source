#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int M=998244353;
int a[505],ans,q,n,m;
long long fac[505]={1};
bool vis[20],p[505];
void dfs(int dep){
    if(dep==n&&n-q>=m){
        ans++;
        ans%=M;
        return;
    }
    if(n-q<m) return;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(!p[dep]||a[i]<=q) q++;
            dfs(dep+1);
            if(!p[dep]||a[i]<=q) q--;
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    for(long long i=1;i<=502;i++){
        fac[i]=(fac[i-1]*i)%(long long)M;
    }
    scanf("%d%d",&n,&m);
    getchar();
    int l=0,l2=0;
    for(int i=0;i<n;i++){
        char k=getchar();
        p[i]=(k=='0'?false:true);
        l+=(int)p[i];
    }
    int j=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]==0) j++;
    }
    if(n<=18){
        dfs(0);
        cout<<ans;
        return 0;
    }
    if(n==m){
        if(l<n||j!=0){
            cout<<0;
        }
        cout<<fac[n];
        return 0;
    }
    if(m==1){
        if(l!=0){
            sort(a,a+n);
            int cnt=0;
            for(int i=0;i<n;i++){
                if(a[i]==0) cnt++;
            }
            if(cnt==n) cout<<0;
            else if(cnt==0) cout<<fac[n];
            else cout<<fac[n-1];
        }
        else cout<<0;
        return 0;
    }
    if(l==n){
        cout<<fac[n];
        return 0;
    }

    return 0;
}
