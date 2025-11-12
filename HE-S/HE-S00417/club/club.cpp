#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],ans,cnt[4];
struct node{
    int mx,_mx,idm,mxv;
    bool operator < (const node &b)const{
        return _mx > b._mx;
    }
}b[N];
struct Node{
    int v,id;
    bool operator < (const Node &b)const{
        return v > b.v;
    }
}c[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                c[j]={a[i][j],j};
            }
            sort(c+1,c+4);
            // cout<<mx<<' '<<_mx<<' '<<idm<<'\n';
            b[i]={c[1].v,c[1].v-c[2].v,c[1].id,c[2].v};
        }
        sort(b+1,b+n+1);
        ans=0;cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;i++){
            int id=b[i].idm;
            if(cnt[id] >= n/2) ans+=b[i].mxv;
            else ans+=b[i].mx,cnt[id]++;
            // cout<<ans<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}