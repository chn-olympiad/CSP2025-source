#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,cnt=1;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        int c;
        cin>>c;
        cnt*=i;
        cnt=cnt%998244353;
    }
    cout<<cnt;
    return 0;
}
