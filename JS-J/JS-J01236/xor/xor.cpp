#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500010],s[500010];
ll check(){
    ll cnt = 0;
    for(int l = 1;l<=n;){
        bool f = 0;
        for(int r = l;r<=n;r++){
            if((s[r]^s[l-1]) == k){
                cnt++;
                l = r+1;
                f = 1;
                break;
            }
        }
        if(!f)l++;
    }
    return cnt;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        s[i] = s[i-1]^a[i];
    }
    cout<<check();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
