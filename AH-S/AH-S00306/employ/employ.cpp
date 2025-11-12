#include<bits/stdc++.h>
#define P 998244353
using namespace std;
int n,m,k[510];
string c;
long long ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>c;
    for(int i=1;i<=m;i++){
        cin>>k[i];
        if(k[i]==0)
            n--;
    }
    if(n<m){
        cout<<0<<endl;
        return 0;
    }
    for(int i=2;i<=n;i++)
        ans=(ans*i)%P;
    cout<<ans<<endl;
    return 0;
}
