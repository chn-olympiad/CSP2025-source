#include<bits/stdc++.h>
const int N=1e5+5,INF=1e9;
using namespace std;
int n,m,s,a[N][5],t[N],c[5],tg,dlt[N],cd;
bool cmp(int x,int y){return x<y;}
void sv(){
    cin>>n,m=(n>>1),s=cd=tg=0,c[1]=c[2]=c[3]=0;
    for(int i=1,mn,mx;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        mx=max(max(a[i][1],a[i][2]),a[i][3]);
        s+=mx;
        for(int j=1;j<=3;j++)if(a[i][j]==mx)t[i]=j;
        c[t[i]]++;
    }
    for(int i=1;i<=3;i++)if(c[i]>m)tg=i;
    if(tg==0){cout<<s<<endl;return;}
    for(int i=1,mn;i<=n;i++)if(t[i]==tg){
        mn=INF;
        for(int j=1;j<=3;j++)if(j!=t[i])
            mn=min(mn,a[i][t[i]]-a[i][j]);
        dlt[++cd]=mn;
    }
    sort(dlt+1,dlt+cd+1,cmp);
    cd=c[tg]-m;
    for(int i=1;i<=cd;i++)s-=dlt[i];
    cout<<s<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;while(T--)sv();
    return 0;
}