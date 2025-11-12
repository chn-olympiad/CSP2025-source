#include<bits/stdc++.h>
using namespace std;
int a[100010][10];
int b[100010];
int vis[10];
struct node{
    int x,id,lll;
    bool operator <(const node &xxx)const{
        return xxx.x<x;
    }
};
priority_queue <node> q;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0;i<7;i++)
        {
            vis[i]=0;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
            {
                vis[1]++;
                ans+=a[i][1];
                b[i]=1;
            }
            else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3])
            {
                vis[2]++;
                ans+=a[i][2];
                b[i]=2;
            }
            else if(a[i][3]>=a[i][2] && a[i][3]>=a[i][1])
            {
                vis[3]++;
                ans+=a[i][3];
                b[i]=3;
            }
        }
        if(vis[1]>(n/2)){
            for(int j=1;j<=n;j++){
                if(a[j][1]-a[j][2]<a[j][1]-a[j][3] && b[j]==1){
                    node t;
                    t.id=2;t.x=min(a[j][1]-a[j][2],a[j][1]-a[j][3]);t.lll=j;
                    q.push(t);
                }
                else if(a[j][1]-a[j][2]>a[j][1]-a[j][3] && b[j]==1){
                    node t;
                    t.id=3;t.x=min(a[j][1]-a[j][2],a[j][1]-a[j][3]);t.lll=j;
                    q.push(t);
                }
            }
            while(vis[1]>(n/2)){
                node s=q.top();
                q.pop();
                if(vis[s.id]<(n/2)){
                    ans-=s.x;
                    vis[s.id]++;
                    vis[1]--;
                }
                else{
                    if(s.id==2){s.id=3;s.x=(a[s.lll][1]-a[s.lll][3]);}
                    if(s.id==3){s.id=2;s.x=(a[s.lll][1]-a[s.lll][2]);}
                    q.push(s);
                }
            }
        }
        while(!q.empty())
            {
                q.pop();
            }
        if(vis[2]>(n/2)){
            for(int j=1;j<=n;j++){
                if(a[j][2]-a[j][1]<a[j][2]-a[j][3] && b[j]==2){
                    node t;
                    t.id=1;t.x=min(a[j][2]-a[j][1],a[j][2]-a[j][3]);t.lll=j;
                    q.push(t);
                }
                else if(b[j]==2 && a[j][2]-a[j][1]<a[j][2]-a[j][3]){
                    node t;
                    t.id=3;t.x=min(a[j][2]-a[j][1],a[j][2]-a[j][3]);t.lll=j;
                    q.push(t);
                }
            }
            while(vis[2]>(n/2)){
                node s=q.top();
                q.pop();
                if(vis[s.id]<(n/2)){
                    ans-=s.x;
                    vis[s.id]++;
                    vis[2]--;
                }
                else{
                    if(s.id==1){s.id=3;s.x=(a[s.lll][2]-a[s.lll][3]);}
                    if(s.id==3){s.id=1;s.x=(a[s.lll][2]-a[s.lll][1]);}
                    q.push(s);
                }
            }
        }
        while(!q.empty())
            {
                q.pop();
            }
        if(vis[3]>(n/2)){
            for(int j=1;j<=n;j++){
                if(a[j][3]-a[j][2]<a[j][3]-a[j][1] && b[j]==3){
                    node t;
                    t.id=2;t.x=min(a[j][3]-a[j][2],a[j][3]-a[j][1]);t.lll=j;
                    q.push(t);
                }
                else if(b[j]==3 && a[j][3]-a[j][2]>=a[j][3]-a[j][1]){
                    node t;
                    t.id=1;t.x=min(a[j][3]-a[j][2],a[j][3]-a[j][1]);t.lll=j;
                    q.push(t);
                }
            }
            while(vis[3]>(n/2)){
                node s=q.top();
                q.pop();
                if(vis[s.id]<(n/2)){
                    ans-=s.x;
                    b[s.lll]=s.id;
                    vis[s.id]++;
                    vis[3]--;
                }
                else{
                    if(s.id==2){s.id=1;s.x=(a[s.lll][3]-a[s.lll][1]);}
                    if(s.id==1){s.id=2;s.x=(a[s.lll][3]-a[s.lll][2]);}
                    q.push(s);
                }
            }
        }
        while(!q.empty())
            {
                q.pop();
            }
        cout<<ans<<"\n";
    }
    return 0;
}
