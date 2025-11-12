#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m;
ll rate[100010][4];
ll ans=0;
int ha[101][101][101]={0};
bool spa=true;
void dfs(int c,int x,int y,int z,ll sum){
    if(sum<ha[x][y][z])
        return;
    ha[x][y][z]=sum;
    if(c>n){
        ans=max(ans,sum);
        return ;
    }
    if(x<m)
        dfs(c+1,x+1,y,z,sum+rate[c][1]);
    if(y<m)
        dfs(c+1,x,y+1,z,sum+rate[c][2]);
    if(z<m)
        dfs(c+1,x,y,z+1,sum+rate[c][3]);
}
vector<int>v;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        memset(ha,0,sizeof(ha));
        cin>>n;
        m=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>rate[i][j];
                if(j!=1&&rate[i][j]!=0)
                    spa=false;
                v.push_back(rate[i][1]);
            }

        }
        if(spa){
            sort(v.begin(),v.end(),cmp);
            for(int i=0;i<m;i++)
                ans+=v[i];
            cout<<ans;
            ans=0;
            spa=true;
            continue;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}

