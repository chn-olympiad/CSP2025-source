//GZ-S00016 中央民族大学附属中学贵阳学校 伍兴睿麟
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,q,ans,z[200005];
pair<string,string>p[200005],Q;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>p[i].fi>>p[i].se;
    }
    for(int k=1;k<=q;k++){
        cin>>Q.fi>>Q.se;
        ans=0;
        for(int i=1;i<=n;i++){
            if(Q.fi.find(p[i].fi)!=-1){
                int x=Q.fi.find(p[i].fi);
                if((Q.fi.substr(0,x)+p[i].se+Q.fi.substr(x+p[i].fi.size(),Q.fi.size()-x))==Q.se) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
