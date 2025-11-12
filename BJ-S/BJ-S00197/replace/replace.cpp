#include <bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string> a[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    while(q--){
        string x,y;
        cin>>x>>y;
        int ans=0;
        for(int i=1;i<=n;i++){
            string c_x=x;
            int cnt=c_x.find(a[i].first,0);
            if(cnt==string::npos)
                continue;
            c_x.replace(cnt,a[i].first.size(),a[i].second);
            if(c_x==y)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}