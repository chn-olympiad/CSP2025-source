#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
int t,n,res;
int d[4];
int w[N][4];
vector<int> g;
void dfs(int x,int cnt){
    //for(auto d:g){
    //    cout<<d<<" ";
    //}
    //cout<<"\n"<<cnt<<"\n";
    if(x==n+1){
        res = max(res,cnt);
        return ;
    }
    //cout<<"!!!"<<d[1]<<" "<<d[2]<<" "<<d[3]<<"\n";
    if(d[1]+1<=n/2) {
        g.push_back(1);
        d[1]++;
        dfs(x+1,cnt+w[x][1]);
        d[1]--;
        g.pop_back();

    }
    if(d[2]+1<=n/2) {
        g.push_back(2);
        d[2]++;
        dfs(x+1,cnt+w[x][2]);
        d[2]--;
        g.pop_back();

    }
    if(d[3]+1<=n/2) {
        g.push_back(3);
        d[3]++;
        dfs(x+1,cnt+w[x][3]);
        d[3]--;
        g.pop_back();

    }
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        for(int i=1;i<=n;i++) memset(w,0,sizeof(w));
        memset(d,0,sizeof(d));
        res = 0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>w[i][j];
            }
        }
        dfs(1,0);
        cout<<res<<"\n";
    }


    return 0;
}
