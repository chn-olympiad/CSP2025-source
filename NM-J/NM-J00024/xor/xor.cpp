#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],ans,m;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        m=max(m,a[i]);
        if(a[i]==k){
            ans++;
            a[i]=-1;
        }
    }
    if(m<(k/2)){
        cout<<0;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n-i;j++){
            if((a[j]!=-1)&&(a[j+1]!=-1))a[j]^=a[j+1];
            else a[j]=-1;
            if(a[j]==k){
                ans++;
                a[j]=-1;
            }
        }
    }
    cout<<ans;
    return 0;
}
