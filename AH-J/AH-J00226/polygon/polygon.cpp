#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],cnt;
bool f;
void dfs(long long d,long long c,long long sum){
    if(sum>2*a[d]&&c>=3){
        cnt=(cnt+1)%998244353;
    }
    for(int i=d+1;i<=n;i++){
        dfs(i,c+1,sum+a[i]);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1]&&i>=2){
            f=1;
        }
    }
    sort(a+1,a+1+n);
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    dfs(0,0,0);
    cout<<cnt;
    return 0;
}
