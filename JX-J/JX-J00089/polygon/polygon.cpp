#include<bits/stdc++.h>
using namespace std;

int n,a[5001],c[5001];
long long ans=0;
inline void dfs(int i,int s,int last,int sum){
    if (i>=3&&s>last*2&&sum>=3&&c[i-1]!=0){
        ans++;
    }
    if (i==n+1){
        return;
    }
    for (int j=0;j<=1;j++){
        c[i]=j;
        if (c[i]==1) {
            last=a[i];
            dfs(i+1,s+a[i],last,sum+1);
        }
        else{
            dfs(i+1,s,last,sum);
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;i++){
        scanf ("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    dfs(1,0,0,0);
    printf("%lld",ans%998244353);
    return 0;
}
