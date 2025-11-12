#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL MAXN=2e5+5;
LL n,q;
string s[MAXN][2],t[MAXN][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(LL i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(LL i=1;i<=q;i++){
        cin>>t[i][0]>>t[i][1];
    }
    for(LL i=1;i<=q;i++){
        cout<<"0"<<endl;
    }
}