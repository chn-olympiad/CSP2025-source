#include<bits/stdc++.h>
using namespace std;

struct node{
    int pre,ls,prg,ppl,zy;
};

bool cmp(node a, node b){
    if(a.zy!=b.zy)
        return a.zy<b.zy;
    if(a.ls!=b.ls)
        return a.ls>b.ls;
    return a.pre>b.pre;
}

node mk(int pre, int prg, int ppl){
    node a;
    a.pre=pre, a.prg=prg, a.ppl=ppl;
    a.ls = 0;
    return a;
}
int g[5];
bool vis[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n;
    int ans, cnt;
    int a1,a2,a3;
    node b1,b2,b3;
    cin>>T;
    while(T--){
        vector<node> l;
        memset(vis,0,sizeof(vis));
        g[1]=g[2]=g[3]=ans=cnt=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a1>>a2>>a3;
            b1=mk(a1,1,i);
            b2=mk(a2,2,i);
            b3=mk(a3,3,i);
            if(b1.pre<b2.pre) swap(b1,b2);
            if(b2.pre<b3.pre) swap(b2,b3);
            if(b1.pre<b2.pre) swap(b1,b2);
            b1.zy=1, b2.zy=2, b3.zy=3;
            b2.ls = b2.pre-b3.pre;
            b1.ls = b1.pre-b2.pre;
            l.push_back(b1); l.push_back(b2); l.push_back(b3);
        }
        sort(l.begin(),l.end(),cmp);

        for(int i=0;i<3*n;i++){
            if(vis[l[i].ppl] || g[l[i].prg]>=n/2) continue;
            g[l[i].prg]++, vis[l[i].ppl]=1;
            ans+=l[i].pre, cnt++;
            if(cnt>=n)
                break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
