#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int A=0,B=0,C=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(k==a[i]) C++;
        if(a[i]!=0&&a[i]!=1){
            B=1;

        }
        if(a[i]!=1)A=1;
    }
    if(A==0){
        cout<<n/2;
        return 0;
    }
    if(B==0){
        if(k==0){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    ans++;
                }
                if(a[i]==1&&a[i+1]==1){
                    ans++;
                }
            }
            cout<<ans;
            return 0;
        }else{
            int y=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    y++;
                }
            }
             cout<<y;
             return 0;
        }

    }
    cout<<C;
return 0;
}
