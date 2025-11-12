#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    bool f1=true,f2=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f1=false;
        if(a[i]!=0&&a[i]!=1)f2=false;
    }
    if(f1&&k==0){
        cout<<n/2;
        return 0;
    }
    if(f2&&k<=1){
        if(k==1){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1)ans++;
            }
            cout<<ans;
        }else{
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0)ans++;
            }
            for(int i=1;i<=n;){
                int cunt=0;
                if(a[i]==0){
                    i++;
                    continue;
                }
                while(a[i]==1){
                    cunt++;
                    i++;
                }
                ans+=cunt/2;
            }
            cout<<ans;
        }
        return 0;
    }
    return 0;
}
