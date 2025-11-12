#include<bits/stdc++.h>
using namespace std;
int n,q,ans;string str;
struct pa{string x,y;}p[200010],qe[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    for(int i=1;i<=q;i++)cin>>qe[i].x>>qe[i].y;
    for(int i=1;i<=q;i++){
        ans=0;
        for(int j=1;j<=n;j++){
            for(int fr=0;fr<=(int)qe[i].x.size()-(int)p[j].x.size();fr++){
                string tmp=qe[i].x;
                if(tmp.substr(fr,p[j].x.size())!=p[j].x)continue;
                if(tmp.replace(fr,p[j].y.size(),p[j].y)==qe[i].y){
                    ++ans;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
