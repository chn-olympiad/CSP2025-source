#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,mod=998244353;
int sum[N],n,a[N],s;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            for(int o=j+1;o<=n;++o){
                if((a[o]+a[j])>a[i]){
                    int k=n-o;
                    k=((k+1)*k%mod)>>1;
                    s=(s+k+1)%mod;
                }
                else{
                    for(int p=o+1;p<=n;p++){
                        if((sum[p]-sum[o-1]+a[j])>a[i]){
                            int k=n-p;
                            k=((k+1)*k%mod)>>1;
                            s=(s+k+1)%mod;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<s;
    return 0;
}
