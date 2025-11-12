#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+10;
const long long mod=998244353;
long long n, a[maxn], b[maxn], f[maxn]{0}, maxnum=-1, ans=0;
bool check(int x){
    int cnt;
    for(int i=0; i<x; i++){
        cnt+=b[i];
    }
    if(cnt>2*maxnum){
        return true;
    }
    return false;
}
void dfs(int x, int lmaxnum){
    if(check(x)){
        ans++;
        return ;
    }
    else{
        for(int i=0; i<n; i++){
            if(!f[i]){
                b[x]=a[i];
                f[i]=1;
                if(a[i]>maxnum){
                    lmaxnum=maxnum;
                    maxnum=a[i];
                }
                dfs(x+1, maxnum);
                f[i]=0;
                maxnum=lmaxnum;
            }
        }
    }
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    else if(n==3){
        sort(a, a+n);
        if(a[n-1]<a[1]+a[0]){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    else{
        dfs(0, -1);
        cout<<ans%mod;
    }
    return 0;
}
