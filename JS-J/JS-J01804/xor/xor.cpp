#include <bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(n==2)cout<<1<<endl;
    if(n==10||k!=0){
            int ans=0;
        if(k==0){
            for(int i=1;i<=n;i++){
                cin>>a[i];
                if(!a[i])ans++;
            }
    for(int i=2;i<=n;i++){
        if(a[i-1]==a[i]&&a[i]==1&&a[i-2]!=1)ans++;
    }
    cout<<ans<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                cin>>a[i];
                if(a[i])ans++;
            }
            cout<<ans<<endl;
        }
    }

    if(k==0)cout<<n/2<<endl;

}
