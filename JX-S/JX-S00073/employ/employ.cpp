#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,l,c[505];
string s;
long long wow(int x){
    long long s=1;
    for(int i=2;i<=x;i++)s=s%mod*i;
    return s%mod;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("employ3.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s,l=n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0)l--;
    }
    cout<<wow(l);
    return 0;
}
