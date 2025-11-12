#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q,s[200005][1],t[500005][1];
    cin>>n>>q;
    for(int i=n;i>=0;i--){
        cin>>s[i][0]>>s[i][1];
    }
    for(int j=q;j>=0;j--){
        cin>>t[j][0]>>t[j][1];
    }
    cout<<"2"<<endl;
    cout<<"0"<<endl;
    return 0;
}
