
//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+10;
int n;
long long dp[N][3];
long long p[N][3];
int vis[N];
int cntt=0;
//vector<pair<int,int> >aans;
long long dfs(int u,long long ret,int cnt1,int cnt2,int cnt3,int op){//cout<<u<<' '<<ret<<' '<<op<<'\n';
    if(cnt1>n||cnt2>n||cnt3>n)return -114514;
    //if(dp[u][op])return dp[u][op];
    if(cntt==n*2){
        //for(auto it:aans){cout<<it.first<<'*'<<it.second<<' ';}cout<<endl;
        return /*cout<<ret<<endl,*/ret;
    }
    long long ans=-1;
    /*
    if(cnt1==n||cnt2==n||cnt3==n){
        cnt=0;
        if(op==0)ans=max(dfs(u,ret,cnt1,cnt2+1,cnt3,1),ans);
        cnt=0;
        ans=max(dfs(u,ret,cnt1,cnt2,cnt3+1,2),ans);
        return ans;
    }
    */
    for(int i=1;i<=n*2;i++){
        if(!vis[i]){
            op=0;
            vis[i]=1,cntt++;//aans.push_back({i,op+1});
            ans=max(dfs(i,ret+p[i][op],cnt1+1,cnt2,cnt3,op),ans);
            cntt--,vis[i]=0;;//aans.pop_back();vis[i]=0;
            op=1;
            vis[i]=1,cntt++;//aans.push_back({i,op+1});
            ans=max(dfs(i,ret+p[i][op],cnt1,cnt2+1,cnt3,op),ans);
            cntt--,vis[i]=0;;//aans.pop_back();vis[i]=0;
            op=2;
            vis[i]=1,cntt++;//aans.push_back({i,op+1});
            ans=max(dfs(i,ret+p[i][op],cnt1,cnt2,cnt3+1,op),ans);
            cntt--,vis[i]=0;;//aans.pop_back();vis[i]=0;
        }
    }
    return /*dp[u][op]=max(dp[u][op],ans),*/ans;
}
int ttmp[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        cin>>n;
        bool flA=1,flB=1;
        for(int i=1;i<=n;i++){
            cin>>p[i][0]>>p[i][1]>>p[i][2];
            if(p[i][1]!=0||p[i][2]!=0)flA=0;
            else ttmp[i]=p[i][0];
            if(p[i][2]!=0)flB=0;
        }
        if(flA){
            sort(ttmp+1,ttmp+n+1,greater<int>());
            long long ans=0;
            for(int i=1;i<=n/2;i++){sum+=ttmp[i];}
            cout<<sum<<endl;
            continue;
        }else if(flB){
            sort(ttmp+1,ttmp+n+1,greater<int>());
            long long ans=0;
            for(int i=1;i<=n/2;i++){sum+=ttmp[i];}
            cout<<sum<<endl;
            continue;
        }
        if(n<=4){
        n=n/2;long long ans=-1;
        for(int i=1;i<=n*2;i++){
            //memset(dp,0,sizeof(dp));
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            cntt=1;
            //aans.push_back({i,1});
            ans=max(dfs(i,p[i][0],1,0,0,0),ans);
            //aans.clear();
        }cout<<ans<<endl;
        }else{
            memset(dp,0,sizeof(dp));
        //dp[id][op]
        //表示在前id-1个人已经处理好，现准备将第id个人放到第op个社团时的价值
        //dp[id][op]=max({dp[id-1][k]});其中k为还可以放人的社团数量
            //n=n/2;
            int cnt[]={0,0,0};
            for(int id=1;id<=n;id++){
                for(int op=0;op<=2;op++){
                    if(cnt[op]<=n){
                        for(int k=0;k<=2;k++){
                            //cnt[op]++;
                            if(dp[id][op]<dp[id-1][k]+p[id][op]){
                                dp[id][op]=dp[id-1][k]+p[id][op];
                                cnt[op]++;
                            }
                        }
                    }
                }
            }
            /*
            for(int id=1;id<=n;id++){
                for(int op=0;op<=2;op++){
                    cout<<dp[id][op]<<' ';
                }cout<<'\n';
            }
            */
            //for(int i=0;i<=2;i++)cout<<cnt[i]<<' ';cout<<'\n';
            cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
        }
    }
    return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1
1:(1)(3)
2:(4)
3:(2)


4
0 1 0
0 1 0
0 2 0
0 2 0
1:(1)(2)
2:(3)(4)
3:

2
10 9 8
4 0 0
1:(1)(2)
2:
3:

10 9
4 8
*/