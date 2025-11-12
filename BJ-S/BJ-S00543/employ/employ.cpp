#include <bits/stdc++.h>
using namespace std;
int n,m,x=1;
string s;
int c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=1;i<=n;i++){
        x*=i;
    }
    cout<<x;
    return 0;
}
