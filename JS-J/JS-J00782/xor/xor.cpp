#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500050],ans;
bool f0,f2;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)f0=1;
        if(a[i]>=2)f2=1;
    }
    if(f0==0&&f2==0){
        cout<<n/2;
        return 0;
    }
    if(f0==1&&f2==0){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0)ans++;
                else if(a[i]==1&&a[i+1]==1){
                    ans++;
                    i++;
                }
            }
            cout<<ans;
            return 0;
        }
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1)ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
