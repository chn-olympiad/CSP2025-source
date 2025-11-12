#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long k;
    cin>>n>>k;
    long long maxa=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
        sum[i]=sum[i-1]^a[i];
    }
    if(maxa<=1){
        int ans=0;
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1)ans++;
            }
            cout<<ans;
        }else{
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    ans++;
                    cnt=0;
                }else{
                    cnt++;
                    if(cnt==2){
                        cnt=0;
                        ans++;
                    }
                }
            }
            cout<<ans;
        }
        return 0;
    }
    int cnt=0,q=1;
    for(int r=1;r<=n;r++){
        for(int l=q;l<=r;l++){
            if((sum[r]^sum[l-1])==k){
                cnt++;
                q=r+1;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
