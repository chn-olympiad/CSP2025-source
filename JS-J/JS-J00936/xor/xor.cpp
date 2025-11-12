#include<bits/stdc++.h>
using namespace std;
const int INT=5*1e5+5;
int dp[INT];
int n,k;
int a[INT];
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool tfa=1,tfb=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            tfa=0;
        }
        if(a[i]!=1&&a[i]!=0){
            tfb=0;
        }
    }
    if(k==0){
        if(tfa){
            cout<<n/2;
            return 0;
        }
        if(tfb){
            for(int i=1;i<=n;i++){
                int cnt;
                while(a[i]==1&&i<=n){
                    cnt++;
                    i++;
                }
                ans+=cnt/2;
            }
            for(int i=1;i<=n;i++){
                int cnt;
                while(a[i]==0&&i<=n){
                    cnt++;
                    i++;
                }
                ans+=cnt/2;
            }
            cout<<ans;
            return 0;
        }
    }
    if(k==1){
        for(int i=1;i<n;i++){
            if((a[i]==0&&a[i+1]==1)||a[i]==1&&a[i+1]==0){
                ans++;
                i++;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
