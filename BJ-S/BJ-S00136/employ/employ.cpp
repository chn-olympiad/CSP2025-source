#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],sx[505];
bool f[505],ff[505],ky=1;
long long as;
string s;
void wk(int dq){
    if(dq==n){
        int ls=0;
        for(int i=1;i<=n;i++){
            if(ls>=a[sx[i]]||!f[i]){
                ls++;
            }
        }
        if(n-ls>=m){
            as=(as+1)%998244353;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!ff[i]){
            ff[i]=1;
            sx[dq+1]=i;
            wk(dq+1);
            ff[i]=0;
        }
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        f[i]=s[i-1]-'0';
        if(a[i]==0||f[i]==0){
            ky=0;
        }
    }
    if(m==n){
        if(ky){
            long long ans=1;
            for(long long i=1;i<=n;i++){
                ans=ans*i%998244353;
            }
            cout << ans;
        }else{
            cout << 0;
        }
        return 0;
    }
    wk(0);
    cout << as;
    return 0;
}
