#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m>>s;
    vector<int>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=m+1;i<=n;i++)m=m*i%998244353;
    cout<<m;
    return 0;
}