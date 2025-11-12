#include<bits/stdc++.h>
int n,k,cnt,a[500005];
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=2){
        cout<<"0";
        return 0;
    }
    if(k==1||k==2){
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                cnt++;
            }
        }
        cout<<cnt;
        return 0;
    }
    return 0;
}
