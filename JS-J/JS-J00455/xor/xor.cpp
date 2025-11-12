#include <bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k) continue;
        int res=0;
        while(a[i]!=k && i<=n){
            res^=a[i];
            i++;
            if(res==k){
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
