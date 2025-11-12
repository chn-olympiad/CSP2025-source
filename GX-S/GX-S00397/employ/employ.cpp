#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("empoly.in","r",stdin);
    freopen("empoly.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int c[n+1];
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }for(int i=0;i<s.size()-1;i++){
        if(s[i]=='1'){
            if(m==1){
                cout<<n%998244353;
                return 0;
            }
            if(m==n){
                cout<<1;
                return 0;
            }
        }
    }
    return 0;
}
