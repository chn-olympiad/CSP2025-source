#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],maxn,yihuo,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(k==0&&a[i]==0){
            cout<<1;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            yihuo^=a[j];
            if(yihuo==k){
                cnt++;
                yihuo=0;
            }
        }
    }
    cout<<cnt;
    return 0;
}
