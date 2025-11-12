#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],c[N];
void ansB(){
    if(k==0){
        int ans=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){ans++;cnt=0;}
            else{
                cnt++;
                if(cnt==2){
                    ans++;
                    cnt=0;
                }
            }
        }
        cout<<ans<<endl;
        return;
    }else{
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1)ans++;
        }
        cout<<ans<<endl;
        return;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    bool A=1,B=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=c[i-1]^a[i];
        if(a[i]!=1)A=0;
        if(a[i]>1)B=0;
    }
    if(k==0&&A){cout<<n/2<<endl;return 0;}
    if(k<2&&B){ansB();return 0;}
    int l=0,ans=0;
    for(int i=1;i<=n;i++){
        for(int j=l;j<=i;j++){
            int x;
            if(j==0)x=c[i];
            else x=c[i]^c[j-1];
            if(i==j)x=a[i];
            if(x==k){
                ans++;
                l=i+1;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
