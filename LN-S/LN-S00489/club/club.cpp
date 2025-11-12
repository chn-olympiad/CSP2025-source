#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
struct node{
    int a,b,c;
    int mx,mxp;
    int d;
}p[N];
int n,ans;
vector<int>cnt[5];
bool cmp(int A,int B){return A>B;}
int STL_max(int A,int B){return A>B?A:B;}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            p[i]=(node){x,y,z,0,0,0};
            p[i].mx=STL_max(x,STL_max(y,z));
            if(p[i].mx==x)p[i].mxp=1,p[i].d=STL_max(y,z)-x;
            else if(p[i].mx==y)p[i].mxp=2,p[i].d=STL_max(z,x)-y;
            else p[i].mxp=3,p[i].d=STL_max(x,y)-z;
            ans+=p[i].mx;
            cnt[p[i].mxp].push_back(p[i].d);
        }
        int A=cnt[1].size();
        int B=cnt[2].size();
        int C=cnt[3].size();
        int hn=n>>1;
        if(A>hn){
            sort(cnt[1].begin(),cnt[1].end(),cmp);
            for(int i=1;i<=A-hn;i++){
                ans+=cnt[1][i-1];
            }
        }
        if(B>hn){
            sort(cnt[2].begin(),cnt[2].end(),cmp);
            for(int i=1;i<=B-hn;i++){
                ans+=cnt[2][i-1];
            }
        }
        if(C>hn){
            sort(cnt[3].begin(),cnt[3].end(),cmp);
            for(int i=1;i<=C-hn;i++){
                ans+=cnt[3][i-1];
            }
        }
        cout<<ans<<endl;
        cnt[1].clear();
        cnt[2].clear();
        cnt[3].clear();
        ans=0ll;
    }
    return 0;
}
