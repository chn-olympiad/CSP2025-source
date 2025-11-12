#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t, n, a[N][4], cnt1, cnt2, cnt3, ans, cc1, cc2, cc3, vis[N];
struct aaa{
    int v, id;
};
bool cmp(aaa a, aaa b){
    if(a.v!=b.v) return a.v<b.v;
    return a.id<b.id;
}
aaa c1[N], c2[N], c3[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        memset(vis,0,sizeof vis);
        memset(c1,0,sizeof c1);
        memset(c2,0,sizeof c2);
        memset(c3,0,sizeof c3);
        cnt1=0;
        cnt2=0;
        cnt3=0;
        cc1=0;
        cc2=0;
        cc3=0;
        ans=0;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                c1[++cc1]={a[i][1]-a[i][2],i};
                c1[++cc1]={a[i][1]-a[i][3],i};
                cnt1++;
                ans+=a[i][1];
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                c2[++cc2]={a[i][2]-a[i][1],i};
                c2[++cc2]={a[i][2]-a[i][3],i};
                cnt2++;
                ans+=a[i][2];
            }
            else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
                c3[++cc3]={a[i][3]-a[i][2],i};
                c3[++cc3]={a[i][3]-a[i][1],i};
                cnt3++;
                ans+=a[i][3];
            }
        }
        sort(c1+1,c1+cc1+1,cmp);
        sort(c2+1,c2+cc2+1,cmp);
        sort(c3+1,c3+cc3+1,cmp);
        if(cnt1>n/2){
            int l=1;
            for(int i=cnt1;i>n/2;i--){
                while(vis[c1[l].id]) l++;
                ans-=c1[l].v;
                vis[c1[l].id]=1;
            }
        }
        if(cnt2>n/2){
            int l=1;
            for(int i=cnt2;i>n/2;i--){
                while(vis[c2[l].id]) l++;
                ans-=c2[l].v;
                vis[c2[l].id]=1;
            }
        }
        if(cnt3>n/2){
            int l=1;
            for(int i=cnt3;i>n/2;i--){
                while(vis[c3[l].id]) l++;
                ans-=c3[l].v;
                vis[c3[l].id]=1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
