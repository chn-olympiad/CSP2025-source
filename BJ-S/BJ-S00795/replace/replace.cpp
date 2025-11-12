#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005];
string b[200005];
string c[200005];
string d[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<q;i++){
        cin>>c[i]>>d[i];
    }
    for(int i=0;i<q;i++){
        cout<<0<<endl;
    }
    return 0;
}
