#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,t=0;
    string s1;
    cin>>n>>m>>s1;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x)  t++;
    }
    long long s=1;
    for(int i=t;i>=1;i--){
        s=s*i%998244353;
    }
    cout<<s;
    return 0;
}
