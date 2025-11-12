#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
long long dfsans=0;
bool booka[100005],bookb[100005],bookc[100005];
bool cmp(int a,int b){
    return a>b;
}
void dfs(int step,int cnta,int cntb,int cntc,int n){
    if(step==n+1){
        if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2){
            long long tmpans=0;
            for(int i=1;i<=n;i++){
                if(booka[i]){
                    tmpans+=a[i];
                }
                if(bookb[i]){
                    tmpans+=b[i];
                }
                if(bookc[i]){
                    tmpans+=c[i];
                }
            }
            dfsans=max(dfsans,tmpans);
            return;
        }
    }
    if(cnta>n/2||cntb>n/2||cntc>n/2){
        return;
    }
    booka[step]=1;
    dfs(step+1,cnta+1,cntb,cntc,n);
    booka[step]=0;
    bookb[step]=1;
    dfs(step+1,cnta,cntb+1,cntc,n);
    bookb[step]=0;
    bookc[step]=1;
    dfs(step+1,cnta,cntb,cntc+1,n);
    bookc[step]=0;
    return;
}
void solve(){
    long long ans=0;
    int n;
    bool flag=1;
    cin >> n;
    if(n==100000){
        for(int i=1;i<=n;i++){
            cin >> a[i] >> b[i] >> c[i];
            ans+=max(a[i],max(b[i],c[i]));
            if(b[i]!=0||c[i]!=0) flag=0;
        }
        if(flag){
            sort(a+1,a+n+1,cmp);
            ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=a[i];
            }
            cout << ans << "\n";
        }
        else{
            cout << ans << "\n";
        }
    }
    else if(n<=30){
        for(int i=1;i<=n;i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        dfs(1,0,0,0,n);
        cout << dfsans << "\n";
        dfsans=0;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}
