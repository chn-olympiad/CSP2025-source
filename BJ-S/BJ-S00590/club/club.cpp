#include<bits/stdc++.h>
using namespace std;

//long long file limit memory

const int N=1e5+10;
int T,n,ans;
struct node{
    int a,m;
    bool operator < (const node &x)const{
        return m>x.m;
    }
};
priority_queue<node> q1,q2,q3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        while(!q3.empty()) q3.pop();
        scanf("%d",&n),ans=0;
        for(int i=1,x,y,z,maxx;i<=n;i++){
            scanf("%d%d%d",&x,&y,&z);
            maxx=max(x,max(y,z));
            if(maxx==x){
                q1.push((node){x,x-max(y,z)});
            }else if(maxx==y){
                q2.push((node){y,y-max(x,z)});
            }else{
                q3.push((node){z,z-max(x,y)});
            }
            ans+=maxx;
        }
        while(q1.size()>n/2){
            ans-=q1.top().m;
            q1.pop();
        }
        while(q2.size()>n/2){
            ans-=q2.top().m;
            q2.pop();
        }
        while(q3.size()>n/2){
            ans-=q3.top().m;
            q3.pop();
        }
        printf("%d\n",ans);
    }
    return 0;
}
