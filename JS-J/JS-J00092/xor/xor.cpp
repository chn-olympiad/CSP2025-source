#include<bits/stdc++.h>
#define itn int
#define fro for
#define elif else if
#define endl "\n"
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using namespace std;
ll n,k,a[10000007],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    IOS;
    cin>>n>>k;
    bool A=1,B=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            A=0;
            if(a[i]!=0)B=0;
        }
    }
    if(A&&k==0){
        cout<<n/2;
        return 0;
    }
    if(B){
        if(k==1){
            for(int i=1;i<=n;i++)if(a[i]==1)ans++;cout<<ans;return 0;
        }else{
            for(int i=1;i<=n;i++){
                if(a[i]==0)ans++;
                if(a[i]==1&&a[i+1]==1){
                    i++;
                    ans++;
                }
            }
            cout<<ans;return 0;
        }
    }
    ll d=0;
    for(int i=1;i<=n;i++){
        d^=a[i];
        if(d==k){
            d=0;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
