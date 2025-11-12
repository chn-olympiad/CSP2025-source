#include<bits/stdc++.h>
#define fastIO (ios::sync_with_stdio(0),cin.tie(0))
using namespace std;

const int Maxn=1e5+7;
typedef long long ll;
struct Node{
    int id,v;
    ll Delta;
    friend bool operator<(Node a,Node b){
        return a.Delta<b.Delta;
    }
};

int n,_;
ll sum;
int b[Maxn][4],u[4];
ll a[Maxn][4];
priority_queue<Node> change[4];

int main(){
    fastIO;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>_;
    while(_--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            b[i][1]=1;b[i][2]=2;b[i][3]=3;
            sort(b[i]+1,b[i]+4,[&](int k,int l){return a[i][k]>a[i][l];});

            if(u[b[i][1]]+1<=n/2){
                u[b[i][1]]++;
                sum+=a[i][b[i][1]];
                change[b[i][1]].push({i,b[i][2],a[i][b[i][2]]-a[i][b[i][1]]});
            }else{
                int id=change[b[i][1]].top().id,v=change[b[i][1]].top().v;
                ll Delta=change[b[i][1]].top().Delta;
                if(a[i][b[i][1]]+Delta<=a[i][b[i][2]]){
                    u[b[i][2]]++;
                    sum+=a[i][b[i][2]];
                    change[b[i][2]].push({i,b[i][3],a[i][b[i][3]]-a[i][b[i][2]]});
                }
                else{
                    u[v]++;
                    sum+=a[i][b[i][1]]+Delta;
                    change[v].push({id,b[id][3],b[id][3]-b[id][2]});
                    change[b[i][1]].pop();
                    change[b[i][1]].push({i,b[i][2],a[i][b[i][2]]-a[i][b[i][1]]});
                }
            }
        }
        cout<<sum<<'\n';

        sum=u[1]=u[2]=u[3]=0;
        while(!change[1].empty())change[1].pop();
        while(!change[2].empty())change[2].pop();
        while(!change[3].empty())change[3].pop();
    }
    return 0;
}
