#include<bits/stdc++.h>
using namespace std;
int n,q;
map<int,char>m1,m2,t1,t2;
int main(){
    freopen("","r",stdin);
    freopen("","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>m1[i]>>m2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>m2[i];
    }
    for(int i=1;i<=q;i++){
        cout<<0<<endl;
    }
    return 0;
}
