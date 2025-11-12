#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,a[N][5],b[N],c[N],d[N];
void work(){
    cin>>n;
    int ans=0,cntb=0,cntc=0,cntd=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        int mx=max(max(a[i][1],a[i][2]),a[i][3]);
        if(a[i][1]==mx){
            b[++cntb]=a[i][1]-max(a[i][2],a[i][3]);
        }else if(a[i][2]==mx){
            c[++cntc]=a[i][2]-max(a[i][1],a[i][3]);
        }else if(a[i][3]==mx){
            d[++cntd]=a[i][3]-max(a[i][2],a[i][1]);
        }
        ans+=mx;
    }
    sort(b+1,b+cntb+1);
    sort(c+1,c+cntc+1);
    sort(d+1,d+cntd+1);
    int xq=n/2;
    for(int i=1;i<=cntb-xq;i++){
        ans-=b[i];
    }
    for(int i=1;i<=cntc-xq;i++){
        ans-=c[i];
    }
    for(int i=1;i<=cntd-xq;i++){
        ans-=d[i];
    }
    cout<<ans<<endl;
    return ;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--) work();
    return 0;
}