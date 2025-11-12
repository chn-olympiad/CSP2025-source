#include <bits/stdc++.h>
using namespace std;
struct edge{
    int nm,v,cs;
}p[300005];

long long ans,n,ans1,ans2,ans3,an1,an2,an3,bx;
bool vis[100005];
bool cmp(edge x,edge y){
    if(y.v<x.v)return 1;
    else return 0;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--){
        memset(p,0,sizeof(p));
        memset(vis,0,sizeof(vis));
        ans=0,ans1=0,ans2=0,ans3=0;
        an1=0,an2=0,an3=0;
        cin>>n;
        for(int i=1;i<=3*n;){
            cin>>p[i].v>>p[i+1].v>>p[i+2].v;

            if(p[i+1].v!=0||p[i+2].v!=0)bx=1;

            p[i].nm=i/3+1,p[i+1].nm=i/3+1,p[i+2].nm=(i+2)/3;
            p[i].cs=1,p[i+1].cs=2,p[i+2].cs=3;
            i+=3;
        }

        sort(p+1,p+1+3*n,cmp);
        if(!bx){
            for(int i=1;i<=n/2;i++){
                ans+=p[3*i-2].v;
            }
            cout<<ans<<endl;
            return 0;
        }
        for(int i=1;i<=3*n;i++){
            if(vis[p[i].nm])continue;
            if(p[i].cs==1&&an1<n/2){
                ans1+=p[i].v,an1++,vis[p[i].nm]=1;
            }
            else if(p[i].cs==2&&an2<n/2){
                ans2+=p[i].v,an2++,vis[p[i].nm]=1;
            }
            else if(p[i].cs==3&&an3<n/2){
                ans3+=p[i].v,an3++,vis[p[i].nm]=1;
            }
        }
        ans=ans1+ans2+ans3;
        cout<<ans<<endl;
        /*for(int i=1;i<=3*n;i++){
            cout<<i<<' '<<p[i].v<<' '<<p[i].nm<<' '<<p[i].cs<<endl;
        }*/
    }
    return 0;
}