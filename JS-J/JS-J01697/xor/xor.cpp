#include<bits/stdc++.h>
using namespace std;
long long k,n,a[500005],d,ans,cnt=0;
bool A=1,B=1,C=1;
void dfs(long long x,long long p,long long m){
    cnt++;
    if (p>n){
        if (m==k) x++;
        ans=max(ans,x);
        return ;
    }
    if (m==k){
        ans=max(ans,x+1);
        for (long long i=p+1;i<=n;i++){
            dfs(x+1,i,a[i]);
        }
    }
    dfs(x,p+1,m^a[p+1]);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (long long i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]!=1)A=0;
        if (a[i]>1) B=0;
        if (a[i]>255) C=0;
    }
    if (A){
        if (k>1) cout<<0<<endl;
        else if (k==1) cout<<n<<endl;
        else cout<<n/2<<endl;
        return 0;
    }
    if (B){
        if (k>1) {
            cout<<0<<endl;
            return 0;
        }
        if (k==1&&a[1]==1) ans++;
        if (k==0&&a[1]==0) ans++;
        for (int i=2;i<=n;i++){
            if (k==1){
                if (a[i]==1) ans++;
            }else{
                if (a[i]==0) ans++;
                if (a[i]==1){
                    if (a[i-1]==1) ans++,a[i]=0;
                }
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    if (C){
        if (k>255){
            cout<<0<<endl;
            return 0;
        }
    }
    if (n<=30){
        for (int i=1;i<=n;i++)dfs(0,i,a[1]);
    }
    cout<<ans<<endl;
    return 0;
}
