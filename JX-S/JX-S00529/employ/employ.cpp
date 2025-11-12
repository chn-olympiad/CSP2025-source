#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,num;
string s;
int c[505],x[505];
long long ans;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i=0;i<s.size();i++){
        x[i+1]=(int)(s[i]-'0');
        if(x[i+1]==1) num++;
    }
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }
    if(num==n){
        int tt=0;
        for(int i=1;i<=n;i++){
            if(c[i]==0) tt++;
        }
        tt=n-tt;
        if(tt<m){
            cout << "0";
            return 0;
        }
        else{
            ans=1;
            for(int i=1;i<=n;i++){
                ans*=i;
                ans%=mod;
            }
            cout << ans;
            return 0;
        }
    }
    if(m==n){
        cout << "0";
        return 0;
    }
    if(n<=10){
        int p[15];
        for(int i=1;i<=n;i++) p[i]=i;
        do{
            int ren=0,guo=0;
            for(int i=1;i<=n;i++){
                if(c[p[i]]<=guo){
                    guo++;
                    continue;
                }
                if(x[i]==1) ren++;
                else guo++;
            }
            if(ren>=m){
                ans++;
            }
        }while(next_permutation(p+1,p+n+1));
        cout << ans%mod;
        return 0;
    }
    cout << "0";
    return 0;
}
