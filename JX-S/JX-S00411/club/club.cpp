#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[5];
long long ans,dp[5][100005];
struct node{
    int x,y,z;
    int a1,a2,a3;
}b[100005];
bool cmp(node u,node v){
    if(u.x!=v.x) return u.x>v.x;
    if(u.y!=v.y) return u.y>v.y;
    return u.z>v.z;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            int a1,a2,a3;cin>>a1>>a2>>a3;
            if(a1<=a2&&a2<=a3)
                b[i]={a3,a2,a1,3,2,1};
            if(a3<=a2&&a2<=a1)
                b[i]={a1,a2,a3,1,2,3};
            if(a2<=a1&&a1<=a3)
                b[i]={a3,a1,a2,3,1,2};
            if(a3<=a1&&a1<=a2)
                b[i]={a2,a1,a3,2,1,3};
            if(a1<=a3&&a3<=a2)
                b[i]={a2,a3,a1,2,3,1};
            if(a2<=a3&&a3<=a1)
                b[i]={a1,a2,a3,1,3,2};
        }
        sort(b+1,b+1+n,cmp);
        memset(cnt,0,sizeof(cnt));
        ans=0;
        if(n==2){
            for(int i=1;i<3;i++){
                memset(cnt,0,sizeof(cnt));
                int sum=0;
                if(i==1) cnt[b[1].a1]++,sum+=b[1].x;
                else cnt[b[1].a2]++,sum+=b[1].y;
                for(int j=1;j<3;j++){
                    if(j==1) cnt[b[2].a1]++,sum+=b[2].x;
                    else cnt[b[2].a2]++,sum+=b[2].y;
                    if(cnt[1]>1||cnt[2]>1||cnt[3]>1)
                        continue;
                    if(sum>ans) ans=sum;
                }
            }
            cout<<ans;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(cnt[b[i].a1]<n/2){
                ans+=b[i].x;
                cnt[b[i].a1]++;
            }else if(cnt[b[i].a2]<n/2){
             //   cout<<b[i].y<<' ';
                ans+=b[i].y;
                cnt[b[i].a2]++;
            }else{
                ans+=b[i].z;
                cnt[b[i].a3]++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
