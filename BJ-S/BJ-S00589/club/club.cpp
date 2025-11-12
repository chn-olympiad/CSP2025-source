#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int MAXN=1e5+10;
int n,t;
int a[MAXN][4],dlt[MAXN];
vector<int> b[4];
bool cmp(int x,int y){
    return dlt[x]>dlt[y];
}
void Work(){
    cin>>n;
    int ans=0;
    for(int i=1;i<=3;i++){
        b[i].clear();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
        int k=1;
        for(int j=2;j<=3;j++){
            if(a[i][j]>a[i][k]){
                k=j;
            }
        }
        ans+=a[i][k];
        b[k].push_back(i);
        dlt[i]=1e9;
        for(int j=1;j<=3;j++){
            if(j!=k){
                dlt[i]=min(dlt[i],a[i][k]-a[i][j]);
            }
        }
    }
    // cout<<"ans:"<<ans<<endl;
    for(int i=1;i<=3;i++){
        if(b[i].size()>n/2){
            sort(b[i].begin(),b[i].end(),cmp);
            while(b[i].size()>n/2){
                int k=b[i].back();
                b[i].pop_back();
                // cout<<"dlt:"<<dlt[k]<<endl;
                ans-=dlt[k];
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        Work();
    }
    return 0;
}