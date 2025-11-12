#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    //ios::sync_with_stdio(false);
    int t,n ,a1,a2,a3,ans;
    int b[10010] ={0};//[10]={0};
    cin >>n>>q;
    string s = n;
    for (int i=1;i<=3;i++){
        cin >>s>>a2>>a3;

        for (int j=1;j<=n;j++){
             b[j] =max(a1,a2,a3);
             }
    }
    for (int i=1;i<=n;i++){
        ans += b[i];
    }
    cout << ans;

    }
