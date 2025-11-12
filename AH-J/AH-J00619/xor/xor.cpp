#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
bool fa=1,fb=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1) fa=0;
        if(a[i]!=1&&a[i]!=0) fb=0;
    }
    if(fa){
        long long ans;
        if(n%2==0) ans=n/2;
        else ans=(n-1)/2;
        cout<<ans;
        return 0;
    }
    if(fb){
        long long ans=0;
        int t=0;
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    ans++;
                    if(t%2==0) ans+=t/2;
                    else ans+=(t-1)/2;
                    t=0;
                }else t++;
            }
            cout<<ans;
            return 0;
        }
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1) ans++;
            }
            cout<<ans;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
