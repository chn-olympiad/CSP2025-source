#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,ans;
int a[200020][4];
int f[200020][5];
int s[200020];
int cnt[4];
void init(){
    for(int i=1;i<=n;i++){
        if(a[i][1]>a[i][2]){
            if(a[i][1]>a[i][3]){
                f[i][1]=1;
                if(a[i][2]>a[i][3]){
                    f[i][2]=2;
                }else{
                    f[i][2]=3;
                }
            }else{
                f[i][1]=3;
                f[i][2]=1;
            }
        }else{
            if(a[i][2]>a[i][3]){
                f[i][1]=2;
                if(a[i][1]>a[i][3]){
                    f[i][2]=1;
                }else{
                    f[i][2]=3;
                }
            }else{
                f[i][1]=3;
                f[i][2]=2;
            }
        }
        f[i][3]=a[i][f[i][1]]-a[i][f[i][2]];
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    init();
    cnt[1]=cnt[2]=cnt[3]=0;
    for(int i=1;i<=n;i++){
        cnt[f[i][1]]++;
    }
    m=0;
    for(int i=1;i<=3;i++){
        if(cnt[i]>n/2){
            m=i;
            break;
        }
    }
    ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[i][f[i][1]];
    }
    if(m==0){
        cout<<ans<<endl;
        return;
    }
    k=0;
    for(int i=1;i<=n;i++){
        if(f[i][1]==m){
            s[++k]=f[i][3];
        }
    }
    sort(s+1,s+1+k);
    for(int i=1;i<=cnt[m]-n/2;i++){
        ans-=s[i];
    }
    cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
