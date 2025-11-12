#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,ans,a[N];
bool flag1,flag2;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag1=1;
        if(a[i]!=1&&a[i]!=0) flag2=1;
    }
    if(!flag1){
        if(n%2) cout<<0;
        else cout<<n/2;
        return 0;
    }
    if(!flag2){
        if(k==0){
            int sum=0;
            for(int i=1;i<=n;i++){
                if(a[i]) sum++;
            }
            if(sum%2){
                cout<<0;
                return 0;
            }
            for(int i=1;i<=n;i++){
                if(!a[i]) ans++;
                else{
                    i++;
                    while(!a[i]&&i<=n) i++;
                    ans++;
                }
            }
        }
        else{
            int sum=0;
            bool f=0;
            for(int i=1;i<=n;i++){
                if(a[i]) sum++;
            }
            if(!(sum%2)){
                cout<<0;
                return 0;
            }
            for(int i=1;i<=n;i++){
                if(!a[i]) ans++;
                else{
                    if(!f&&a[i]){
                        ans++;
                        f=1;
                    }
                    else{
                        i++;
                        while(!a[i]&&i<=n) i++;
                        ans++;
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
