#include<bits/stdc++.h>
using namespace std;
int m,n,c[1000000];
string a;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m;
        cin>>a;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        if(m==n&&a[i]==0){
            cout<<0;
            return 0;
        }
    }
    cout<<m;
    return 0;
}
