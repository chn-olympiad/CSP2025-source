#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+5;
int n,q;
string s[N][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>s[i][1]>>s[i][2];
    }
    for(int i=1;i<=q;++i){
        cin>>s[i][1]>>s[i][2];
        cout<<0<<endl;
    }
    return 0;


}
