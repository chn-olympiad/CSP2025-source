#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+2;
ll n,k,a[N],s,ans,pos;
bool pd;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==1){
        for(int i=1;i<=n;i++) if(a[i]==1) ans++;
        cout<<ans;
    }
    else if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0) ans++;
            if(a[i]==1){
                if(a[i+1]==1){
                    ans++;
                    i++;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}