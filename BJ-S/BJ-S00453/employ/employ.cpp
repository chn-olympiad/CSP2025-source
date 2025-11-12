#include<bits/stdc++.h>
using namespace std;
long long a[505],comp[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int len=s.size();
    comp[1]=1;
    for(int i=2;i<=n;i++){
        comp[i]=(comp[i-1]*i);
        //cout<<comp[i]<<endl;
    }
    cout<<comp[n]%998244353;
    return 0;
}
