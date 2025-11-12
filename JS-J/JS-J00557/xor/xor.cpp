#include<bits/stdc++.h>
using namespace std;
int a[500005],ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    bool s1=true;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            s1=false;
        }
    }
    if(s1){
        cout<<n/2;
    }else{
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1]){
                ans++;
                i++;
                continue;
            }else{
                if(a[i]==a[i+2]){
                    ans++;
                    i+=2;
                    continue;
                }else{
                    i++;
                }
            }
        }
        cout<<ans;
    }
    return 0;

}
