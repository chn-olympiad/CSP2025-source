#include<bits/stdc++.h>
#define int unsigned int long long
using namespace std;
int a[5005];
const int p=998244353;
int s[5005];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3) cout<<0;
    else if(n==3){
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
    }else{
        int maxn=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxn=max(a[i],maxn);
        }
        if(maxn==1){
            int ans=0;
            s[0]=1;
            for(int i=1;i<=n;i++){
                s[i]=1;
                for(int j=2;j<=i;j++) s[i]=(s[i]*j)%p;
            }
            for(int i=3;i<=n;i++) ans=(ans+(s[n]/(s[i]*s[n-i]%p)))%p;
            cout<<ans<<endl;
        }
    }
    return 0;
}
