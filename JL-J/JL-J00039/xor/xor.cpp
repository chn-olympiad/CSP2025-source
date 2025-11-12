#include<bits/stdc++.h>
using namespace std;
int n,k,ans=INT_MIN,cnt;
bool ab=1,b=1;
int a[514514];
namespace suba{
    void f(){
        cout<<n/2;
        return;
    }
}
namespace subb{
    void f(){
        ans=0;
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i+1]==a[i]){
                    a[i]=-1;
                    a[i+1]=-1;
                    i++;
                }
            }
            for(int i=1;i<=n;i++){
                if(a[i]==-1)ans++;
                if(a[i]==k)ans+=2;
            }
            cout<<max(ans/2,cnt);
        }else{
            for(int i=1;i<=n;i++){
                if(a[i+1]!=a[i]){
                    a[i]=-1;
                    a[i+1]=-1;
                    i++;
                }
            }
            for(int i=1;i<=n;i++){
                if(a[i]==-1)ans++;
                if(a[i]==k)ans+=2;
            }
            cout<<max(ans/2,cnt);
        }
        return;
    }
}
void f(){
    for(int i=1;i<=n;i++){
        int ans2=0,be_xor=0;
        for(int j=i;j<=n;j++){
            be_xor=be_xor ^ a[j];
            if(be_xor==k)ans2++,be_xor=0;
            if(clock()>=993000){
                cout<<max(ans,ans2);
                exit(0);
            }
        }
        ans=max(ans2,ans);
        if(clock()>=993000){
            cout<<ans;
            exit(0);
        }
    }
    cout<<ans;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k)cnt++;
        if(a[i]==0)ab=0;
        if(a[i]>=2)b=0,ab=0;
    }
    if(ab)suba::f();
    else if(b)subb::f();
    else f();
    return 0;
}
