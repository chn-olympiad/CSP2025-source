#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5100],ans,b[5100];
bool bo;

void v(int x){
    int maxn,cnt=0;
    if(x==n){
        for(int i=0;i<n;++i){
            if(b[i]==1){
                cnt+=a[i];
                maxn=a[i];
            }
        }
        if(cnt>maxn*2){
            ans=(ans+1)%mod;
            /*for(int i=0;i<n;++i) {
                if(b[i]==1) cout<<i<<" ";
            }
            cout<<endl;
            */
        }
        return ;
    }
    v(x+1);
    b[x]=1;
    v(x+1);
    b[x]=2;
    return ;
}

signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(a[i]!=1) bo=1;
    }
    sort(a,a+n);
    if(n<3){
        cout<<0;
        return 0;
    }else if(n==3){
        if(a[0]+a[1]>a[2]) cout<<1;
        else cout<<0;
        return 0;
    }else if(!bo){
        int l=1;
        for(int i=0;i<n;++i) l=l*2%mod;
        int c2=n*(n-1)/2%mod;
        int c3=n*(n-1)*(n-2)/6%mod;
        int ans=(l+mod-n-c2-c3-1)%mod;
        //cout<<l<<" "<<c2<<" "<<c3<<" ";
        cout<<ans<<endl;
        return 0;
    }
    v(0);
    cout<<ans<<endl;
    return 0;
}
