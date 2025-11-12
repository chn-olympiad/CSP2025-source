#include<bits/stdc++.h>
#define N 100005
#define lo long long
using namespace std;
int T,n;
int num[5];
lo ans;
struct P{
    int id,val;
};
struct MEM{
    P w[5];
    int del,delid;
}mem[N];
void init(){
    memset(mem,0,sizeof(mem));
    ans=num[1]=num[2]=num[3]=0;
}
bool cmp(P x,P y){
    return x.val>y.val;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n;
        int maxn=n/2,st=0,fulid=0;
        init();
        for(int i=1;i<=n;i++){
            cin>>mem[i].w[1].val;
            cin>>mem[i].w[2].val;
            cin>>mem[i].w[3].val;
            mem[i].w[1].id=1;
            mem[i].w[2].id=2;
            mem[i].w[3].id=3;
            sort(mem[i].w+1,mem[i].w+1+3,cmp);
            mem[i].del=mem[i].w[1].val-mem[i].w[2].val;
            mem[i].delid=mem[i].w[2].id;
        }
        for(int i=1;i<=n;i++){
            int id=mem[i].w[1].id;
            ans+=mem[i].w[1].val;
            num[id]++;
            if(num[id]==maxn){st=i;fulid=id;break;}
        }
        if(st==n||st==0) {cout<<ans<<endl;continue;}
        priority_queue<int>q;
        for(int i=1;i<=st;i++){
            int id=mem[i].w[1].id;
            if(id==fulid) q.push(0-mem[i].del);
        }
        //if(q.size()!=maxn) cout<<"wowwww";//This_wont_work_at_anytime
        for(int i=st+1;i<=n;i++){
            int id=mem[i].w[1].id;
            if(id!=fulid){
                ans+=mem[i].w[1].val;
                num[id]++;
                continue;
            }
            int ori_val=mem[i].w[2].val;
            int u=q.top();
            if(mem[i].w[1].val+u>ori_val){//Pick_the_full
                q.pop();
                q.push(0-mem[i].del);
                ans+=mem[i].w[1].val+u;
                continue;
            }
            ans+=mem[i].w[2].val;
        }
        cout<<ans<<endl;
    }
    return 0;
}
