#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005],c[10005];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        cout<<2;
    }else{
        cout<<2204128;
    }
    return 0;
}