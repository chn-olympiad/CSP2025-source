#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.ans", "w", stdout);
    int n,m,x[99999],ans=1;
    cin>>n>>m;
    string a;
    cin>>a;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        ans=ans*i;
    }
    cout<<ans;
    return 0;
}
