#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,a[5010];
bool f=1;
long long ans;
void dfs(int d,int sum,int maxn,int cnt){
    if(d==n+1){
        if(cnt>=3&&sum>2*maxn) ans=(ans+1)%998244353;
        return ;
    }
    dfs(d+1,sum,maxn,cnt);
    dfs(d+1,sum+a[d],max(maxn,a[d]),cnt+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) f=0;
    }
    if(f){
        long long sum=0;
        for(int i=3;i<=n;i++){
            long long t=(i-1)*(i-2)/2;
            sum=(sum+t)%998244353;
        }
        cout<<sum;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
