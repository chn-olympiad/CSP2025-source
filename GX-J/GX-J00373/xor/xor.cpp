#include <bits/stdc++.h>
using namespace std;
int n,k,a[105],ans=0,cnt=0;
int x(int a,int b){
    if (a==b){
        return 0;
    }
    return 1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        if (a[i]==k){
            ans++;
            continue;
        }
        cnt=x(a[i],a[i+1]);
        if (cnt==k){
            ans++;
            i+=2;
            continue;
        }
        for (int j=i+2;j<=n;j++){
            cnt=(cnt,a[j]);
            if (cnt==k){
                i=j+1;
                continue;
            }
        }
    }
    cout<<ans;
    return 0;
}
