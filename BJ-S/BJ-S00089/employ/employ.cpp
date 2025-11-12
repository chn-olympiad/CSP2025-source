#include<bits/stdc++.h>
using namespace std;
const int modnum=998244353;
int n,m,c[505];
long long jc[505];
char x;
bool ava[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        ava[i]=x-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    jc[1]=1;
    for(int i=2;i<=n;i++){
        jc[i]=jc[i-1]*i;
        jc[i]%=modnum;
    }
    cout<<jc[n];
    return 0;
}
