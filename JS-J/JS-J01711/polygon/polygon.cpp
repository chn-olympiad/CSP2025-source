#include<bits/stdc++.h>
using namespace std;
int n , a[100000001];
long long ans = 0;
void dfs(int now ,int he,int ma){
    if(now==n+1){
        if(he>ma*2)
            ans = (ans+1)%998244353;
        return;
    }
    dfs(now+1,he,ma);
    dfs(now+1,he+a[now],max(ma,a[now]));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d" , &n);
    for(int i = 1;i<=n;i++)
        scanf("%d" , &a[i]);
    dfs(1,0,0);
    printf("%lld" , ans);
}
