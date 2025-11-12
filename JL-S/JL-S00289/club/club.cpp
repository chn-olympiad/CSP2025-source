#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
    int c[4];
}a[N];
struct node2{
    int x;
    int y;
};
int bin[4];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i].c[j];
        }
    }
    bin[1]=bin[2]=bin[3]=0;
    for(int i=1;i<=n;i++){
        int tmp=-1,pos=0;
        for(int j=1;j<=3;j++){
            if(a[i].c[j]>tmp){
                tmp=a[i].c[j];
                pos=j;
            }
        }
        bin[pos]++;
    }
    int mxp=0;
    for(int j=1;j<=3;j++){
        if(bin[j]>n/2){
            mxp=j;
        }
    }
    if(!mxp){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=max({a[i].c[1],a[i].c[2],a[i].c[3]});
        }
        cout<<ans<<"\n";
    }else{
        vector<node2> v;
        for(int i=1;i<=n;i++){
            node2 nw;
            nw.y=0;
            for(int j=1;j<=3;j++){
                if(j==mxp){
                    nw.x=a[i].c[j];
                }else{
                    nw.y=max(nw.y,a[i].c[j]);
                }
            }
            v.push_back(nw);
        }
        sort(v.begin(),v.end(),[](node2 x,node2 y){return x.x-x.y>y.x-y.y;});
        int ans=0,cnt=0;
        for(auto i:v){
            if(cnt+1<=n/2){
                ans+=i.x;
                cnt++;
            }else{
                ans+=i.y;
            }
        }
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}