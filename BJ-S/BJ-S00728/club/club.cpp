#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,dp[10005],ar,br,cr;
int a[10005],b[10005],c[10005],maxn[10005],minn[10005],mid[10005];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=0;i<=n;i++){
        dp[i]=0;
        minn[i]=0;
        maxn[i]=0;
        mid[i]=0;
    }
        for(int i=1;i<=n;i++){
         //   cin>>s[i].a;
         //   cout<<1;
          //  cin>>s[i].b;
          //  cout<<2;
            //>>s[i].c;
         //   s[i].maxn=max(s[i].a,max(s[i].b,s[i].c));
        /*
            s[i].minn=min(s[i].a,min(s[i].b,s[i].c));
            if(s[i].a!=s[i].minn&&s[i].a!=s[i].maxn){
               s[i].mid=s[i].a;
            }else if(s[i].b!=s[i].minn&&s[i].b!=s[i].maxn){
                s[i].mid=s[i].b;
            }else{
                s[i].mid=s[i].c;
            }*/
            cin>>a[i]>>b[i]>>c[i];
            maxn[i]=max(a[i],max(b[i],c[i]));
            minn[i]=min(a[i],min(b[i],c[i]));
            if(a[i]!=minn[i]&&a[i]!=maxn[i]){
                mid[i]=a[i];
            }else if(b[i]!=minn[i]&&b[i]!=maxn[i]){
                mid[i]=b[i];
            }else{
                mid[i]=c[i];
            }
        }
        sort(maxn,maxn+n+1,cmp);
        dp[1]=maxn[n];
        for(int i=0;i<=n;i++){
                dp[i]=dp[i-1]+maxn[i];
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
}
