#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int T,n,a[N][5],cnt[5];
ll ans;
void dfs(int x,ll s){
    if(x>n){
        bool f=0;
        for(int i=1;i<=3;i++)
            if(cnt[i]>n/2) f=1;
        if(f==0) ans=max(ans,s);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(cnt[i]>=n/2) continue;
        cnt[i]++;
        dfs(x+1,s+a[x][i]);
        cnt[i]--;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++)
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
/*
反悔贪心。吗？
2h 没调出来(￣、￣) 蒟蒻的做题策略是这样的 嗯
来吧 部分分 30min later 20pts 燃尽了[跪]
你既然多测，那我是真没招了[扶额]

不知道花560来干嘛来了
我还是那句话————竞赛！需要炮灰！
欸，之前刷视频刷到考验网友文笔的“_ _,_ _ _ _。”
评论上是“中国，拒绝签字”等等。今天我也是填上了哈。

遇到考试只有两种人不慌，成绩好的和成绩差的。而我！显然是第二种...
来吧，我怕你不成，还能更差吗！？
*/

/*
神经代码:) 如下
#define P pair<int,int>
#define x first
#define id second
struct node{
    int mx,x,y,z;
}in[N];
bool cmp(node u,node v){
    return u.mx>v.mx;
}
priority_queue<P,vector<P>,greater<P>> q[5];

for(int i=1;i<=n;i++){
    cin>>in[i].x>>in[i].y>>in[i].z;
    in[i].mx=max(in[i].x,max(in[i].y,in[i].z));
}
sort(in+1,in+1+n,cmp);
for(int i=1;i<=n;i++)
    a[i][1]=in[i].x,a[i][2]=in[i].y,a[i][3]=in[i].z;

for(int i=1;i<=3;i++){
    while(!q[i].empty()) q[i].pop();
    cnt[i]=0;
}
for(int i=1;i<=n;i++){
    // cout<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<"\n";
    bool f=0;
    int nd=0,wh=0;
    for(int j=1;j<=3;j++){
        if(a[i][j]==in[i].mx){
            if(cnt[j]<n/2) cnt[j]++,q[j].push({a[i][j],i}),f=1;
            else{
                P u=q[j].top();
                int sec=0,p;
                for(int k=1;k<=3;k++)
                    if(k!=j&&a[u.id][k]>=sec&&cnt[k]<n/2)
                    sec=a[u.id][k],p=k;
                
                if(sec+a[i][j]>u.x){
                    // cout<<i<<" "<<u.id<<" "<<sec<<" "<<p<<"\n";
                    q[j].pop();
                    q[p].push({sec,u.id});
                    q[j].push({a[i][j],i});
                    cnt[p]++;
                    f=1;
                }
            }
        }
        else if(cnt[j]<n/2) nd=max(nd,a[i][j]),wh=j;
    }
    if(f==0){
        cnt[wh]++;
        q[wh].push({nd,i});
    }
}
for(int i=1;i<=3;i++){
    // cout<<q[i].size()<<" ";
    while(!q[i].empty()){
        // cout<<q[i].top().x<<" ";
        s+=q[i].top().x,q[i].pop();
    }
} 
cout<<s<<"\n";
}
*/