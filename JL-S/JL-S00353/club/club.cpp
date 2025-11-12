#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
    int x,y,z;
    int cx,cy,cz;
    bool flag;
    int ii;
}a[100005];
struct edge{
    int c,val,ii,col;
    bool operator < (const edge &xxx) const {
        return c<xxx.c;
    }
};
bool vis[100005];
priority_queue<edge>q,q2;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        for(int i=1;i<=n;i++) vis[i]=0;
        while(!q.empty())q.pop();
        while(!q2.empty())q2.pop();
        long long ans=0;
        cin>>n;
        int mnx=0x3f3f3f3f;
        int mny=0x3f3f3f3f;
        int mnz=0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].ii=i;
            mnx=min(mnx,a[i].x);
            mny=min(mnx,a[i].y);
            mnz=min(mnx,a[i].z);
            a[i].flag=0;
        }
        for(int i=1;i<=n;i++){
            a[i].cx=a[i].x-mnx;
            a[i].cy=a[i].y-mny;
            a[i].cz=a[i].z-mnz;
            q.push({a[i].x,a[i].x,a[i].ii,1});
            q.push({a[i].y,a[i].y,a[i].ii,2});
            q.push({a[i].z,a[i].z,a[i].ii,3});
            q2.push({a[i].cx,a[i].x,a[i].ii,1});
            q2.push({a[i].cy,a[i].y,a[i].ii,2});
            q2.push({a[i].cz,a[i].z,a[i].ii,3});
        }
        int cnt[4]={0};
        int iiii=0;
        while(cnt[1]+cnt[2]+cnt[3]>n||!q.empty()){
            edge tmp=q.top();
            q.pop();
            if(cnt[1]+cnt[2]+cnt[3]==n-1&&!vis[tmp.ii]){
                iiii=tmp.ii;
                break;
            }

            if(!vis[tmp.ii]){
                if(cnt[tmp.col]<n/2){
                    ans+=tmp.val;
                    vis[tmp.ii]=1;
                    cnt[tmp.col]++;
                }
                else continue;
            }
        }

        int mx=max({a[iiii].x,a[iiii].y,a[iiii].z});
        if(a[iiii].x==mx&&cnt[1]<n/2) ans+=a[iiii].x;
        else if(a[iiii].y==mx&&cnt[2]<n/2) ans+=a[iiii].y;
        else if(a[iiii].z==mx&&cnt[3]<n/2) ans+=a[iiii].z;
        for(int i=1;i<=n;i++) vis[i]=0;
        cnt[1]=0;
        cnt[2]=0;
        cnt[3]=0;
        long long ans2=0;
        while(cnt[1]+cnt[2]+cnt[3]>n||!q2.empty()){
            edge tmp=q2.top();
            q2.pop();
            if(cnt[1]+cnt[2]+cnt[3]==n-1&&!vis[tmp.ii]){
                iiii=tmp.ii;
                break;
            }
            if(!vis[tmp.ii]){
                if(cnt[tmp.col]<n/2){
                    ans2+=tmp.val;
                    vis[tmp.ii]=1;
                    cnt[tmp.col]++;
                }
                else continue;
            }
        }

        int mxx=max({a[iiii].x,a[iiii].y,a[iiii].z});
        if(a[iiii].x==mxx&&cnt[1]<n/2) ans2+=a[iiii].x;
        else if(a[iiii].y==mxx&&cnt[2]<n/2) ans2+=a[iiii].y;
        else if(a[iiii].z==mxx&&cnt[3]<n/2) ans2+=a[iiii].z;
        cout<<max(ans,ans2)<<"\n";
    }
    return 0;
}
