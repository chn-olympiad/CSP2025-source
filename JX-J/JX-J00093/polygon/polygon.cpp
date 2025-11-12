#include <bits/stdc++.h>
using namespace std;

int n;
long long a[5010];
bool f[5010];
long long c;

void dfs(int dep){
    if(dep>n){
        long long sum=0;
        long long mmax=-1;
        for(int i=1; i<=n; i++){
            if(f[i]){
                sum+=a[i];
                mmax=max(mmax,a[i]);
            }
        }
        if(sum!=0&&mmax!=-1&&sum>2*mmax){
            c++;
            c=c%998224353;
        }
    }else{
        f[dep]=1;
        dfs(dep+1);
        f[dep]=0;
        dfs(dep+1);
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    dfs(1);
    cout<<c%998224353;
    return 0;
}


