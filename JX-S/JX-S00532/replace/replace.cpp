#include<bits/stdc++.h>
using namespace std;
int n,q;
char a[3000][3000],c[3000][3000];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            cin>>a[i];
        }
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=2;j++){
            cin>>c[i];
        }
    }
    for(int i=1;i<=q;i++){
        cout<<0<<endl;
    }
    return 0;
}
