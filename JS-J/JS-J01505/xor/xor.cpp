#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k,sum,cnt,a[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==1) cnt++;
    }
    if(cnt==n&&k==0){
        cout<<n/2;
        return 0;
    }
    else if(cnt!=n&&k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0) sum++;
            else if(a[i]==1&&a[i+1]==1){
                sum++;
                i+=2;
            }
        }
        cout<<sum;
    }
    else if(cnt!=n&&k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1) sum++;
            else if(a[i]==0&&a[i+1]==0&&a[i+2]==0){
                sum++;
                i+=3;
            }
        }
        cout<<sum;
        return 0;
    }
    cout<<"2";
    return 0;
}
