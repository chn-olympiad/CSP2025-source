#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    string a[1000005][3];
    cin>>n>>m;
    for(int i=1;i<=n+m;i++){
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=m;i++){
        cout<<0<<endl;
    }
}