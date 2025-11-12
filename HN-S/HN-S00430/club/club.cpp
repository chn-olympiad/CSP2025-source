#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
struct aaaa{
    int val,wz;
    bool operator <(const aaaa &a)const{
        return val<a.val;
    }
}a[100010],b[100010],c[100010];
int val[100010][3];
int cnta,cntb,cntc;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        cnta=cntb=cntc=0;
        for(int x=1;x<=n;x++){
            cin>>val[x][0]>>val[x][1]>>val[x][2];
            int mx=max(val[x][0],max(val[x][1],val[x][2]));
            ans+=mx;
            if(mx==val[x][0]){
                int ls=mx-max(val[x][1],val[x][2]);
                a[++cnta]={ls,x};
            }
            else if(mx==val[x][1]){
                int ls=mx-max(val[x][0],val[x][2]);
                b[++cntb]={ls,x};
            }
            else{
                int ls=mx-max(val[x][1],val[x][0]);
                c[++cntc]={ls,x};
            }
        }
        sort(a+1,a+cnta+1);
        sort(b+1,b+cntb+1);
        sort(c+1,c+cntc+1);
        if(cnta>n/2){
            for(int x=1;x<=cnta-n/2;x++){
                ans-=a[x].val;
            }
        }
        else if(cntb>n/2){
            for(int x=1;x<=cntb-n/2;x++){
                ans-=b[x].val;
            }
        }
        else if(cntc>n/2){
            for(int x=1;x<=cntc-n/2;x++){
                ans-=c[x].val;
            }
        }
        cout<<ans<<'\n';
    }
}
/*
1
4
99 0 0
99 0 0
99 0 1
100 98 0
*/