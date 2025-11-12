#include<bits/stdc++.h>
using namespace std;
long long b[500010],a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int cnt=0,cnt2=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(b[i]^b[j]==k)
            cnt++;
            if(b[i]&b[j]==k){
                cnt2++;
            }
        }
    }
    if(cnt>=cnt2&&cnt!=0){
        cout<<cnt;
    }
    else if(cnt!=0&&cnt2!=0){
        cout<<cnt2;
    }
    return 0;
}
