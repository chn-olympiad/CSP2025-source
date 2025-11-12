#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct p{
    int s[3];
    int maxn;
    int dif;
}a[N];
vector<p> x[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].s[0]>>a[i].s[1]>>a[i].s[2];
            a[i].maxn=max(a[i].s[0],a[i].s[1]);
            a[i].maxn=max(a[i].maxn,a[i].s[2]);
            ans+=a[i].maxn;
            if(a[i].maxn==a[i].s[0]){
                a[i].dif=a[i].s[0]-max(a[i].s[1],a[i].s[2]);
                a[i].maxn=0;
            }
            else if(a[i].maxn==a[i].s[1]){
                a[i].dif=a[i].s[1]-max(a[i].s[0],a[i].s[2]);
                a[i].maxn=1;
            }
            else if(a[i].maxn==a[i].s[2]){
                a[i].dif=a[i].s[2]-max(a[i].s[0],a[i].s[1]);
                a[i].maxn=2;
            }
        }
        for(int i=0;i<3;i++) x[i].clear();
        for(int i=1;i<=n;i++){
            x[a[i].maxn].push_back(a[i]);
        }
        for(int i=0;i<3;i++){
            if(x[i].size()>(n/2)){
                sort(x[i].begin(),x[i].end(),[](p a,p b){
                     return a.dif<b.dif;
                });
                int gl=x[i].size()-(n/2);
                for(int j=0;j<gl;j++) ans-=x[i][j].dif;
                break;
            }
        }
        cout<<ans<<'\n';
    }
}
