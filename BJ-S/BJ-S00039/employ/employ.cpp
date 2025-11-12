#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen ("employ.in","r",stdin);
    freopen ("employ.out","w",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    string a;
    cin>>a;
    int b[n];
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
   // for(int i=1;i<=n;i++){
        int renshu=0;
        for(int i=1;i<=a.length();i++){
            if(b[i]<=renshu){
                renshu++;
            }
            if(a[i]=='0'){
                renshu++;
            }
        }
        if(n-renshu>=m){
            cnt++;
        }
    //}
    cout<<cnt%998244353;
    return 0;
}
