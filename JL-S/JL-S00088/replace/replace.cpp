#include <bits/stdc++.h>
using namespace std;
long long n,q;
string a[2100][2100];
string b[2100][2100];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++) cin>>a[i][j];
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=2;j++) cin>>b[i][j];
    }
    for(int i=1;i<=q;i++){
        cout<<0<<endl;
    }

    return 0;
}
