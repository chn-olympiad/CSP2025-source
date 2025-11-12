#include<bits/stdc++.h>
using namespace std;
int n,k,maxn=-1;
int a[500005];
void f(int x,int s,int ans){
    //cout<<x<<" "<<s<<" "<<ans<<"  "<<maxn<<endl<<endl;
    maxn=max(maxn,ans);
    for(int j=x;j<=n;++j){
        s=(s^a[j]);
        if(s==k){
            f(j+1,0,ans+1);
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(k<=1){
        if(k==0){
            int ans=0;
            for(int i=1;i<=n;++i){
                if(a[i]==0){
                    ans++;
                }
            }
            cout<<ans;
        }else if(k==1){
            int ans=0;
            for(int i=1;i<=n;++i){
                if(a[i]==1){
                    ans++;
                }
            }
            cout<<ans;
        }
    }else{
        for(int i=1;i<=n;++i){
            f(i,0,0);
        }
        cout<<maxn;
    }
    return 0;
}
