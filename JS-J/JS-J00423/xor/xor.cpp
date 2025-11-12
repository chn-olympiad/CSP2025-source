#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,k,a[500050],sumxor[500050],ans=0;
    set <long long>s;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    sumxor[0]=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sumxor[i]=(sumxor[i-1]^a[i]);
    }
    s.insert(1);
    for(int l=1,r=1;r<=n;r++){
        auto x = s.upper_bound((sumxor[r]^k)*1000000+l-1);
        if((*x)/1000000==(sumxor[r]^k)){
            ans++;
            l=r+1;
            r=l-1;
            s.insert(sumxor[l-1]*1000000+l);
        }
        else{
            s.insert(sumxor[r]*1000000+r+1);
        }
    }
    cout << ans;
    return 0;
}
