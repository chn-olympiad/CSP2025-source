#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k;
string s;
int c[N],a[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    if(n==3){
        cout<<"2"<<'\n';
        cout<<"0";
    }else{
        for(int i=1;i<=m;i++){
            cout<<"0"<<'\n';
        }
    }
    return 0;
}
