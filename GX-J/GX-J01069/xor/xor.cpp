#include <bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
int n,k,a[N],cnt1=0,cnt=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)cnt1++;
    }
    if(cnt1==n){
        cout<<n;
        return 0;
    }
    if(k==1){
    for(int i=1;i<=n;i++){
        if(a[i]==1) cnt++;
        else if(a[i]==0){
            while(a[i]==0)i++;
            cnt++;
        }
    }
    }
    else if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0) cnt++;
            else if(a[i]==1){
                while(a[i+1]==0)i++;
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
