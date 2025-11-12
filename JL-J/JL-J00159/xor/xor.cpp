#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=0;
        for(int j=i;j<=n;j++){
            ans^=a[j];
            if(ans==k){
                cnt++;
                i=j;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
