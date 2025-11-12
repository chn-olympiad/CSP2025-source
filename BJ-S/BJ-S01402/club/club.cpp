#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define int long long
using namespace std;

const int MAXN=1e5+5;
int t,n,res,a[MAXN][5];
bool f[MAXN];
vector<int> v[5];
struct node{
    int x,t,p;
    //第x行，调整到t需要费用p
    bool operator<(const node& y)const{
        return p<y.p;
    }
}q[MAXN<<2];

int plan[MAXN];
void dfs(int x){
    if(x==n+1){
        int cnt=0;
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;
        for(int i=1;i<=n;i++){
            if(plan[i]==1)cnt1++;
            if(plan[i]==2)cnt2++;
            if(plan[i]==3)cnt3++;
        }
        if(cnt1>n/2)return;
        if(cnt2>n/2)return;
        if(cnt3>n/2)return;
        for(int i=1;i<=n;i++)
            cnt+=a[i][plan[i]];
        res=max(res,cnt);
        return;
    }
    plan[x]=1,dfs(x+1);
    plan[x]=2,dfs(x+1);
    plan[x]=3,dfs(x+1);
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=3;i++)
            v[i].clear();
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int mx=max({a[i][1],a[i][2],a[i][3]});
            if(mx==a[i][1])v[1].push_back(i);
            if(mx==a[i][2])v[2].push_back(i);
            if(mx==a[i][3])v[3].push_back(i);
            ans+=mx;
        }
        if(n<=10){
            res=0;
            dfs(1);
            cout<<res<<endl;
        }
        else{
            int pos=0;
            for(int p=1;p<=3;p++)
                if(v[p].size()>n/2){
                    // cout<<p<<" 不满足要求！"<<endl;
                    int cnt=0;
                    for(int i:v[p]){
                        f[i]=false;
                        for(int j=1;j<=3;j++)
                            if(p!=j)
                                q[++cnt]=node{i,j,a[i][p]-a[i][j]};
                    }
                    // cout<<p<<' '<<v[p].size()<<endl;
                    // for(int i:v[p])cout<<i<<' ';
                    // cout<<endl;
                    sort(q+1,q+cnt+1);
                    // for(int i=1;i<=cnt;i++)
                        // cout<<q[i].x<<' '<<q[i].t<<' '<<q[i].p<<endl;
                    int sz=v[p].size();
                    for(int i=1;i<=cnt;i++){
                        if(f[q[i].x])continue;
                        // if(v[q[i].t].size()==n/2)continue;
                        sz--;
                        v[q[i].t].push_back(q[i].x);
                        ans-=q[i].p;
                        f[q[i].x]=true;
                        if(sz==n/2)break;
                    }
                    pos=p;
                    break;
                }
            //此时p已经完工，剩下的两个可能超标
            for(int p=1;p<=3;p++)
                if(pos!=p&&v[p].size()>n/2){
                    // cout<<p<<" 不满足要求！"<<endl;
                    int lst=6-p-pos;
                    int cnt=0;
                    for(int i:v[p]){
                        f[i]=false;
                        q[++cnt]=node{i,lst,a[i][p]-a[i][lst]};
                    }
                    // cout<<p<<' '<<v[p].size()<<endl;
                    // for(int i:v[p])cout<<i<<' ';
                    // cout<<endl;
                    sort(q+1,q+cnt+1);
                    // for(int i=1;i<=cnt;i++)
                    //     cout<<q[i].x<<' '<<q[i].t<<' '<<q[i].p<<endl;
                    int sz=v[p].size();
                    for(int i=1;i<=cnt;i++){
                        if(f[q[i].x])continue;
                        sz--;
                        v[q[i].t].push_back(q[i].x);
                        f[q[i].x]=true;
                        if(sz==n/2)break;
                    }
                    pos=p;
                    break;
                }
            cout<<ans<<endl;
        }
    }
    return 0;
}