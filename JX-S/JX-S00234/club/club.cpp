#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],b[100001],c[100001],ans,cnta,cntb,cntc,pot;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        cnta=0,cntb=0,cntc=0;
        for(int j=1;j<=n;j++){
            cin>>a[j]<<b[j]>>c[j];
            cnta+=a[j],cntb+=b[j],cntc+=c[j];
        }
        if(!cntb&&!cntc){
            sort(a+1,a+n+1);
            for(int i=n;i>=n/2;i--) ans+=cnta[i];
        }else if(cntb&&!cntc){
            ans=cnta/2+cntb/2;
        }else{
            ans=cntc/3+cntb/3+cnta/3;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
