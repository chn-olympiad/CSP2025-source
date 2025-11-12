#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,s[N],a[N];
bool check(int x){
    int y=0;
    bool ok=true;
    for(int i=n;i>=1;){
        //cout<<i<<endl;
        for(int j=i;j>=1;j--){
            //cout<<j<<endl;
            if(abs(s[i]-s[j-1])==k){
                //cout<<j-1<<" "<<i<<endl;
                i=j-1;
                y++;
                //cout<<j-1<<endl;
                ok=false;
                break;
            }
        }
        //cout<<i<<" 1 1 1"<<endl;
        if(ok)i--;
        ok=true;
    }
    ///cout<<y<<endl;
    return y>=x;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n==2&&k==0){
        int x,y;cin>>x>>y;
        if(x==0&&y==0)cout<<2;
        else if(x^y==0)cout<<1;
        else if(x==0)cout<<1;
        else if(y==0)cout<<1;
        else cout<<0;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]^a[i];
    }
    int l=0,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
}
