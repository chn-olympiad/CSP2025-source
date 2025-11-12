#include<bits/stdc++.h>
using namespace std;
int n,m,c[200005];
string a;
long long ans=1,x;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>a;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    x=n;
    for(int i=1;i<=m;i++){
        ans*=x;
        ans%=998244353;
        x--;
    }
    cout<<ans<<endl;
    return 0;
}

