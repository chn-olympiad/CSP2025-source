#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
