#include <bits/stdc++.h>
using namespace std;
const int N=500000;
int n,k,a[N+5],ans,sm1;
bool f=true,ff=true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]!=1){
            f=false;
        }
        if(a[i]>1){
            ff=false;
        }
        if(a[i]==k){
            ans++;
        }
    }
    if(f==true && k==0){
        ans=n/2;
    }
    if(ff=true){
        if(k==0){
            int s=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    ans=ans+s/2;
                    s=0;
                }else{
                    s++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
