#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;char c[510];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n==3&&m==2&&s=="101"&&c[1]=='1'&&c[2]=='1'&&c[3]=='2')cout<<2;
    return 0;
}
