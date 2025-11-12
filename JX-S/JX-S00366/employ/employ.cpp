#include <bits/stdc++.h>
using namespace std;
int n,q;
string x,y,a,b;
int s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>a>>b;
    }
    for(int i = 1;i<=q;i++){
        cin>>x>>y;
        for(int i = 1;i<=x.size();i++){
            if(x[i]!=y[i])s++;
        }
        if(s==x.size())cout<<0;
        else cout<<s;
    }
    return 0;
}
