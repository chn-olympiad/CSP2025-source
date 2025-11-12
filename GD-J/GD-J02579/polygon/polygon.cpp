#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+5;
const ll mod=998244353;
int n,a[maxn],V;
ll f[maxn][maxn],res,all,cnt[maxn],scnt[maxn];
void Main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        V=max(V,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=V;i++){
        scnt[i]=(scnt[i-1]+cnt[i])%mod;
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=V;j++){
            f[i][j]=(f[i][j]+f[i-1][j])%mod;
            if(j+a[i]<=V){
                f[i][j+a[i]]=(f[i][j+a[i]]+f[i-1][j])%mod;
            }
        }
    }
    int lst=0;
    for(int j=1;j<=V;j++){
        if(!cnt[j]){
            continue;
        }
        while(lst<n&&a[lst+1]<j){
            lst++;
        }
        ll cur=-scnt[j-1];
        for(int i=1;i<=j;i++){
            cur=(cur+f[lst][i])%mod;
        }
        res=(res+cnt[j]*cur%mod)%mod;
    }
    all=1;
    for(int i=1;i<=n;i++){
        all=all*2%mod;
    }
    all=(all-1-n-n*(n-1)/2)%mod;
    res=((all-res)%mod+mod)%mod;
    cout<<(res%mod+mod)%mod<<'\n';
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    Main();
}
/*
9:05（也许是9:10?）: 应该是AK了? 
--------------------
我该在哪里停留? 我问我自己。
--luogu uid:752017--
*/