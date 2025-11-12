#include<bits/stdc++.h>
using namespace std;
int a[500005];
set<int>se;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,cnt=0,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt^=a[i];
        if(cnt==k||se.find(cnt^k)!=se.end()){
            ans++;
            cnt=0;
            se.clear();
        }else se.insert(cnt);
    }
    cout<<ans;
    return 0;
}
