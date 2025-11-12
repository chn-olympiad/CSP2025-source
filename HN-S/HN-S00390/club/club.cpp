#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][3],p[N],W[N];
vector<int> H[3];
void read(){
    cin>>n;
    H[0].clear(),H[1].clear(),H[2].clear();
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        int Max=max(a[i][0],max(a[i][1],a[i][2]));
        if(a[i][0]==Max){
            p[i]=0;
            W[i]=a[i][0]-max(a[i][1],a[i][2]);
        }else if(a[i][1]==Max){
            p[i]=1;
            W[i]=a[i][1]-max(a[i][0],a[i][2]);
        }else{
            p[i]=2;
            W[i]=a[i][2]-max(a[i][1],a[i][0]);
        }
        H[p[i]].push_back(i);
    }
}
bool cmp(int i,int j){return W[i]<W[j];}
void work(){
    int op=-1,ans=0;
    for(int i=1;i<=n;i++) ans+=a[i][p[i]];
    if(H[0].size()*2>n) op=0;
    if(H[1].size()*2>n) op=1;
    if(H[2].size()*2>n) op=2;
    if(op==-1){
        cout<<ans<<'\n';
        return ;
    }
    sort(H[op].begin(),H[op].end(),cmp);
    for(int i=0;i<H[op].size()-n/2;i++) ans-=W[H[op][i]];
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=1;
    cin>>T;
    while(T--){
        read();
        work();
    }
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
    return 0;
}