#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5007], b[5007];
char aa[5007];
map <string ,int>mp;
long long ans=0;

void d(int ct, int mx, long long sum, int ch){
    if(ct==0 ){
        if(sum>mx*2 && ch>=3){
            string s="";
            for(int i=1; i<=ch; ++i){
                s+=aa[i];
                s+=" ";
            }
            //puts("");
            mp[s]++;
            if(mp[s]==1){
                (ans+=1)%=MOD;
            }
            //puts("");
        }
        return;
    }
    for(int i=ct; i>=1; --i){
        //s+=a[i];
        aa[ch+1]=a[i]+'0';
        d(i-1, max(mx, a[i]),sum+a[i], ch+1);
        d(i-1, mx, sum, ch);
    }

}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    d(n, 0, 0, 0);
    cout << ans;
}
