#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N1=2e2+10,N=1e5+10;
int T,n,cur,a[N][4],dp[N1][N1][N1],sum[4],res;
bool b1,b2,vis[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
            if(a[i][2])b1=0;
            if(a[i][3])b2=0;
        }
        res=0;
        if(n<=200){
            for(int i=0;i<=n/2;i++){
                for(int j=0;j<=n/2;j++){
                    for(int k=0;k<=n/2&&i+j+k<=n;k++){
                        int x=i+j+k;
                        dp[i][j][k]=0;
                        if(i)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[x][1]);
                        if(j)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[x][2]);
                        if(k)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[x][3]);
                        if(x>=n){
                            res=max(res,dp[i][j][k]);
                        }
                    }
                }
            }
            cout<<res<<endl;
        }else if(b1){
            priority_queue<pair<int,int> > q;
            for(int i=1;i<=n;i++){
                q.push({a[i][1],i});
            }
            for(int i=1;i<=n/2;i++){
                pair<int,int> temp=q.top();
                int w=temp.first;
                int x=temp.second;
                q.pop();
                res+=w;
            }
            cout<<res<<endl;
        }else if(b2){
            priority_queue<pair<int,int> > q;
            for(int i=1;i<=n;i++){
                q.push({abs(a[i][1]-a[i][2]),i});
            }
            memset(sum,0,sizeof(sum));
            while(!q.empty()){
                pair<int,int> temp=q.top();
                int w=temp.first;
                int x=temp.second;
                q.pop();
                int t=min(a[x][1],a[x][2]),j=int(t==a[x][2])+1;
                res+=t;
                if(sum[j]<n/2){
                    sum[j]++;
                    res+=w;
                }
            }
            cout<<res<<endl;

        }else{
            pair<int,pair<int,int> > q[n*3+4];
            int sz=0;
            for(int i=1;i<=n;i++){
                int mn=1e9;
                for(int j=1;j<=3;j++){
                    mn=min(mn,a[i][j]);
                }
                for(int j=1;j<=3;j++){
                    q[sz++]={a[i][j]-mn,{i,j}};
                }
            }
            res=0;cur=n;
            int top=sz-1,half=n>>1;
            for(int i=1;i<=n;i++){
                vis[i]=0;
            }
            sum[1]=sum[2]=sum[3]=0;
            sort(q,q+sz);
            while(top>=0&&cur){
                pair<int,pair<int,int> > temp=q[top--];
                int w=temp.first;
                int x=temp.second.first;
                int y=temp.second.second;
                if(!vis[x]&&sum[y]<half){
                    vis[x]=1;
                    ++sum[y];
                    res+=a[x][y];
                    --cur;
                }
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/