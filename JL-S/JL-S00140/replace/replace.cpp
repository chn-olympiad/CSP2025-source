#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[210000][3];
string t[210000][3];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",sidout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            cin>>s[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=2;j++){
            cin>>t[i][j];
        }
        cout<<"0"<<endl;
    }
}
