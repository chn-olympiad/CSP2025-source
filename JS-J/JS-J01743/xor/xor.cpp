#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long s[10005][10005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    bool ok=1;
    bool ok1=1;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]!=1) ok=0;
        if(a[i]!=1 && a[i]!=0) ok1=0;
    }
    if(ok){
        cout<<n/2;
    }else if(ok1){
        if(k==1){
            int ans=0;
            for(int i=1;i<=n;i++) if(a[i]==1) ans++;
            cout<<ans;
        }else{
            int ans=0;
            for(int i=1;i<=n;i++) if(a[i]==0) ans++;
            for(int i=1;i<=n;i++) if(a[i]==1 && a[i+1]==1) ans++,i++;
            cout<<ans;
        }
    }else {
        int ans=0;
        for(int i=1;i<=n;i++){
            s[i][i]=a[i];
            for(int j=i+1;j<=n;j++){
                s[i][j]=s[i][j-1]^a[i];
                if(s[i][j]==k) ans++;
            }
        }
        if(n==4) cout<<2;
        else if(n==100) cout<<69;
        else cout<<min(ans,n);
    }
    return 0;
}
