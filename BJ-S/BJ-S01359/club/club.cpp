#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int T,n,m,x,y,z,vis[maxn],ans,d[1000][100];
struct node{
    int val,id;
    bool operator < (const node &a)const {
        return val<a.val;
    }
};
priority_queue<node,vector<node>,less<node> > a1,a2,a3;
bool cmp(node a,node b){ return a.val>b.val; }
int dfs(int less1,int less2,int sum){
    if(less1==0 && less2==0){
        return sum;
    }
    while(vis[a1.top().id]){
        a1.pop();
    }
    while(vis[a2.top().id]){
        a2.pop();
    }
    if(less1==0){
        node a=a2.top();
        a2.pop();
        return dfs(less1,less2-1,sum+a.val);
    }else if(less2==0){
        node a=a1.top();
        a1.pop();
        return dfs(less1-1,less2,sum+a.val);
    }
    if(a2.top()<a1.top()){
        node a=a1.top();
        a1.pop();
        less1--;
        sum+=a.val;
        int ans1=dfs(less1,less2,sum);
        a=a1.top();
        a1.pop();
        node b=a1.top();
        a1.pop();
        a1.push(a);
        int ans2=dfs(less1,less2,sum);
        return max(ans1,ans2);
    }else{
        node a=a2.top();
        a2.pop();
        less2--;
        sum+=a.val;
        int ans1=dfs(less1,less2,sum);
        a=a2.top();
        a2.pop();
        node b=a2.top();
        a2.pop();
        a2.push(a);
        int ans2=dfs(less1,less2,sum);
        return max(ans1,ans2);
    }

}
void solve(int s,int sum,int c1,int c2,int c3){
    if(s==n+1){
        ans=max(ans,sum);
        return ;
    }
    if(c1<n/2)solve(s+1,sum+d[s][1],c1+1,c2,c3);
    if(c2<n/2)solve(s+1,sum+d[s][2],c1,c2+1,c3);
    if(c3<n/2)solve(s+1,sum+d[s][3],c1,c2,c3+1);
    return ;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        bool flag1=0,flag2=0;
        ans=0;cin>>n;
        if(n<=30){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=3;j++){
                    cin>>d[i][j];
                }
            }
            solve(1,0,0,0,0);
            cout<<ans<<endl;
            continue;
        }
        while(!a1.empty())  a1.pop();
        while(!a2.empty())  a2.pop();
        while(!a3.empty())  a3.pop();
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&x,&y,&z);
            if(y!=0)    flag1=1;
            if(z!=0)    flag2=1;
            a1.push({x,i});a2.push({y,i});a3.push({z,i});
        }

        if(!flag1&!flag2){
            for(int i=1;i<=n/2;i++){
                ans+=a1.top().val;
                a1.pop();
            }
            cout<<ans<<endl;
            continue;
        }
        if(!flag2){
            cout<<dfs(n/2,n/2,0)<<endl;
            continue;
        }
        //sort(a1.begin(),a1.end(),cmp);
        //sort(a1.begin(),a1.end(),cmp);
        //sort(a1.begin(),a1.end(),cmp);
        int cnta=0,cntb=0,cntc=0;
        while(cnta+cntb+cntc<n){
            //cout<<cnta<<" "<<cntb<<" "<<cntc<<endl;
            if(cnta<n/2){
                if(cntb<n/2){
                    if(cntc<n/2){
                        node a,b,c;
                        while(vis[a1.top().id]){
                            a1.pop();
                        }
                        while(vis[a2.top().id]){
                            a2.pop();
                        }
                        while(vis[a3.top().id]){
                            a3.pop();
                        }
                        a=a1.top(),b=a2.top(),c=a3.top();
                        if(a.val>=b.val && a.val>=c.val){
                            ans+=a.val;cnta++;
                            vis[a.id]=1;continue;
                        }
                        if(b.val>=a.val && b.val>=c.val){
                            ans+=b.val;cntb++;
                            vis[b.id]=1;continue;
                        }
                        if(c.val>=a.val && c.val>=b.val){
                            ans+=c.val;cntc++;
                            vis[c.id]=1;continue;
                        }
                    }else{
                        node a,b;
                        while(vis[a1.top().id]){
                            a1.pop();
                        }
                        while(vis[a2.top().id]){
                            a2.pop();
                        }
                        a=a1.top(),b=a2.top();
                        if(a.val>=b.val){
                            ans+=a.val;cnta++;
                            vis[a.id]=1;continue;
                        }
                        if(b.val>=a.val){
                            ans+=b.val;cntb++;
                            vis[b.id]=1;continue;
                        }
                    }
                }else{
                    if(cntc<n/2){
                        node a,c;
                        while(vis[a1.top().id]){
                            a1.pop();
                        }
                        while(vis[a3.top().id]){
                            a3.pop();
                        }
                        a=a1.top(),c=a3.top();
                        if(a.val>=c.val){
                            ans+=a.val;cnta++;
                            vis[a.id]=1;continue;
                        }
                        if(c.val>=a.val){
                            ans+=c.val;cntc++;
                            vis[c.id]=1;continue;
                        }
                    }else{
                        node a;
                        while(vis[a1.top().id]){
                            a1.pop();
                        }
                        a=a1.top();
                        ans+=a.val;cnta++;
                        vis[a.id]=1;continue;
                    }
                }
            }else{
                if(cntb<n/2){
                    if(cntc<n/2){
                        node b,c;
                        while(vis[a2.top().id]){
                            a2.pop();
                        }
                        while(vis[a3.top().id]){
                            a3.pop();
                        }
                        b=a2.top(),c=a3.top();
                        if(b.val>=c.val){
                            ans+=b.val;cntb++;
                            vis[b.id]=1;continue;
                        }
                        if(c.val>=b.val){
                            ans+=c.val;cntc++;
                            vis[c.id]=1;continue;
                        }
                    }else{
                        node b;
                        while(vis[a2.top().id]){
                            a2.pop();
                        }
                        b=a2.top();
                        ans+=b.val;cntb++;
                        vis[b.id]=1;continue;
                    }
                }else{
                    if(cntc<n/2){
                        node c;
                        while(vis[a3.top().id]){
                            a3.pop();
                        }
                        c=a3.top();
                        ans+=c.val;cntc++;
                        vis[c.id]=1;continue;
                    }else{
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
