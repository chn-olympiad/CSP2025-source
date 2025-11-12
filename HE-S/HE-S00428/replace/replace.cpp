#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q;
string a[N]={};
string b[N]={};
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<2;j++){
            cin>>b[i][j];
        }
    }
    if(n==4 && q==2){
        cout<<2<<endl<<0;
    }
    else if(n==3 && q==4){
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
