#include<bits/stdc++.h>
#define a3 array<int,4>
using namespace std;
a3 s[300005];
int t,n,h,ans;
bool cmp(a3 x,a3 y){
    if(x[1]>y[0])return x[1]>y[0];
    if(x[0]<y[1])return x[0]<y[1];
    if(x[0]!=y[0])return x[0]<y[0];
    return x[1]>y[1];
}
bool vis[100005],a0=1;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    for(cin>>t;t;t--){
        ans=h=0;memset(vis,0,sizeof vis);
        cin>>n;
        for(int i = 1,a,b,c;i<=n;i++){
            cin>>a>>b>>c;
            if(b!=0||c!=0)a0=0;
            if(a==b&&b==c){
                ans+=a;
                continue;
            }
            s[++h]={b+c,a,i,1};
            s[++h]={a+c,b,i,2};
            s[++h]={a+b,c,i,3};
        }
        sort(s+1,s+h+1,cmp);
        if(a0){
            for(int i = 1;i<=n/2;i++)ans+=s[i][1];
            cout<<ans<<"\n";
            continue;
        }
        int j[4]={0};
        for(int i = 1;i<=h;i++){

            if(vis[s[i][2]]||j[s[i][3]]>=n/2)
                continue;
            ans+=s[i][1];
            vis[s[i][2]]=1;
            j[s[i][3]]++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

