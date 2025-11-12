#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,inf=0x3f3f3f3f;
typedef long long ll;
struct road{
    int city1;
    int city2;
    int cost;
};
struct country{
    int country_cost;
    int c_cost[N];
};
road a[N];
country b[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>a[i].city1>>a[i].city2>>a[i].cost;
    for(int i=1;i<=k;i++){
        cin>>b[i].country_cost;
        for(int j=1;j<=n;j++)
            cin>>b[i].c_cost[j];
    }
    if(k==0){
        int sum=0;
        for(int i=1;i<=m;i++)sum+=a[i].cost;
        cout<<sum;
    }
    return 0;
}
