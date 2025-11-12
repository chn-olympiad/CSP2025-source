#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m>>s;
    int c;
    for (int i=1;i<=n;i++){
        cin>>c;
    }
    int S=1;
    for (int i=1;i<=n;i++){
        S*=i;
    }
    for (int i=1;i<=m;i++){
        S/=i;
    }
    for (int i=1;i<=n-m;i++){
        S/=i;
    }
    cout<<S%998244353;
    return 0;


}
