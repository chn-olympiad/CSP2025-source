#include<bits/stdc++.h>
using namespace std;

int a[5001],c[5001],n;
bool b[5001];
long long ans;
const int M=998244353;

void dfs(int j,int dep){
    for(int k=1;k<=n;k++){
        if(!b[k]){
            b[k]=1;
            c[dep]=a[k];
            if(dep<j)
                dfs(j,dep+1);
            else{
                int T=0;
                for(int l=1;l<=dep;l++)
                    T+=c[l];
                if(T>2*c[dep]){
                    ans++;
                    ans=ans%M;
                }
            }
            b[k]=0;
        }
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int j=3;j<=n;j++){
        dfs(j,1);
        memset(c,0,sizeof(c));
    }
    cout<<ans;
    return 0;
}
