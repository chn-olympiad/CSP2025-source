#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
int a[N][3],cnt[3],bel[N];
vector<int> v;
void solve(){
    int n,ans=0;cin>>n;
    cnt[0]=cnt[1]=cnt[2]=0;
    for(int i=1;i<=n;i++){
        int maxx=-1;
        for(int j=0;j<=2;j++) {
            cin>>a[i][j];
            if(maxx==-1||a[i][j]>a[i][maxx]) maxx=j;
        }
        cnt[maxx]++;ans+=a[i][maxx];
        bel[i]=maxx;
    }
    if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
        cout<<ans<<'\n';
        return ;
    }
    v.clear();
    int op;
    for(int i=0;i<=2;i++) if(cnt[i]>n/2) op=i;
    //cout<<op<<' ';
    if(cnt[op]>n/2){
        for(int i=1;i<=n;i++){
            int max1=-1;
            for(int j=0;j<=2;j++){
                if(j==bel[i]) continue;
                if(max1==-1||a[i][j]>a[i][max1]) max1=j;
            }
            if(bel[i]==op){
                v.push_back(a[i][op]-a[i][max1]);
            }
        }
        sort(v.begin(),v.end());
        int del=cnt[op]-n/2;
        //cout<<del<<" "<<v.size()<<'\n';
        for(int i=0;i<v.size()&&del;i++){
            ans-=v[i];
            del--;
        }
        cout<<ans<<'\n';
    }
    
}
signed main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--) solve();
}