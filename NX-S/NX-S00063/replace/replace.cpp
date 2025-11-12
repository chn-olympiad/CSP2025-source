#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector <string> a(n);
    vector <string> b(n);
    for(int i = 0;i < n;i++){
        cin>>a[i]>>b[i];
    }
    while(m--){
        string x,y;
        cin>>x>>y;
        int ans = 0;
        for(int i = 0;i < n;i++){
            auto r = x.find(a[i]);
            if(r != string::npos){
                x.replace(r,a[i].length(),b[i]);
                if(x == y){
                    ans++;
                }
                x.replace(r,a[i].length(),a[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
