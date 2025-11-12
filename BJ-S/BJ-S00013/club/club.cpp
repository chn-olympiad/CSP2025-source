#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
const int N=1e5+1;
int T;
int n;
int a[N],b[N],c[N];
int ans,ts;
priority_queue<pii,vector<pii>,greater<pii> > x,y;
void dfs(int cur,int sa,int sb,int sc,int sum){
    if(cur>n){
        ans=max(ans,sum);
        return;
    }
    if(sa<n/2) dfs(cur+1,sa+1,sb,sc,sum+a[cur]);
    if(sb<n/2) dfs(cur+1,sa,sb+1,sc,sum+b[cur]);
    if(sc<n/2) dfs(cur+1,sa,sb,sc+1,sum+c[cur]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ts=1,ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(c[i]!=0) ts=-1;
            if(b[i]!=0) ts=min(ts,0);
        }
        if(n<=10) dfs(1,0,0,0,0);
        else{
            if(ts==-1) cout<<"I don't no.";
            else if(ts==1){
                sort(a+1,a+n+1);
                for(int i=n;i>n/2;i--) ans+=a[i];
            }
            else{
                int lx,ly;
                while(!x.empty()) x.pop();
                while(!y.empty()) y.pop();
                for(int i=1;i<=n;i++){
                    if(a[i]>=b[i]) x.push({a[i]-b[i],i});
                    else y.push({b[i]-a[i],i});
                }
                lx=x.size();
                ly=y.size();
                while(lx>ly){
                    auto k=x.top(); x.pop();
                    lx--,ly++;
                    y.push(k);
                }
                while(lx<ly){
                    auto k=y.top(); y.pop();
                    lx++,ly--;
                    x.push(k);
                }
                while(lx--){ans+=a[x.top().second];x.pop();}
                while(ly--){ans+=b[y.top().second];y.pop();}
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}