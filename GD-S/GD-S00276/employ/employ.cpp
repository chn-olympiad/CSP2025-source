#include <bits/stdc++.h>
#define mod 998224353;
using namespace std;

const int N=500;
int n,m,a[N+5],f[N];
string s;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> s;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int mk,c;
    mk=0;
    c=0;
    for(int i=0; i<s.size(); i++){
        for(int j=1; j<=n; j++){
            if(a[j]>=c){
                f[i]++;
            }
            if(s[i]=='1'){
                mk++;
            }else{
                c++;
            }
        }
    }
    if(mk<m){
        cout << 0;
        return 0;
    }
    long long ans=1;
    for(int i=0; i<s.size(); i++){
        if(f[i]<m) f[i]=1;
        ans+=f[i]%mod;
    }
    cout << (ans/2-1)%mod;
    return 0;
}
