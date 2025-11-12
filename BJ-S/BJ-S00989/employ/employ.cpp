#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=503;
int a[maxn],b[maxn],mod=998244353;
int jc(int s){
    if(s==1) return 1;
    else return (s*jc(s-1))%mod;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,ans;
    char c;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c;
        a[i]=(int) c-48;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    if(m==1){
        ans=0;
        int pos;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                pos=i;
                break;
            }
        }
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++){
            if(b[i]>=pos){
                ans=i;
                break;
            }
        }
        cout<<((n-ans+1)*jc(n-1))%mod;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            cout<<0;
            return 0;
        }
    }
    sort(b+1,b+n+1);
    ans=1;
    for(int i=1;i<=n;i++){
        if(b[i]<i){
            cout<<0<<endl;
            return 0;
        }
        else ans=(ans*(b[i]-i+1))%mod;
    }
    cout<<ans;
    return 0;
}
