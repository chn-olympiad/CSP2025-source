#include<bits/stdc++.h>
using namespace std;
string a,b;
string xa[200010],xb[200010];
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>xa[i]>>xb[i];

    }
    for(int i=1;i<=q;i++){
        cin>>a>>b;
        int ans=0;
        for(int j=1;j<=n;j++){
            string aa=a,bb=b;
            if(aa.find(xa[j])!=-1)aa.erase(aa.find(xa[j]),xa[j].size());
            if(bb.find(xb[j])!=-1)bb.erase(bb.find(xb[j]),xb[j].size());
            if(aa==bb)ans++;

        }
        cout<<ans<<'\n';
    }
    return 0;
}
