#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e5+10;
int t,n;
struct node{
    int x,name,num;
}a[3*N];
int aa[N][3];
int cnt;
bool cmp(node x,node y){
    if(x.x!=y.x){
        return x.x>y.x;
    }
    return x.name<y.name;
}
int k[4];
bool vis[N];
ll ans;
struct node1{
    int x,name,num;
    bool friend operator<(node1 x,node1 y){
        return x.x<y.x;
    }
};
priority_queue<node1>q[4];
int main(){
    IOS
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(vis,0,sizeof(vis));
        ans=0;
        cnt=0;
        while(!q[1].empty()){
            q[1].pop();
        }
        while(!q[2].empty()){
            q[2].pop();
        }
        while(!q[3].empty()){
            q[3].pop();
        }
        k[1]=k[2]=k[3]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cnt++;
                cin>>a[cnt].x;
                aa[i][j]=a[cnt].x;
                a[cnt].num=j;
                a[cnt].name=i;
            }
        }
        sort(a+1,a+1+cnt,cmp);

        for(int i=1;i<=cnt;i++){
            if(vis[a[i].name]){
                continue;
            }
            if(k[a[i].num]>=n/2){
                node1 t=q[a[i].num].top();
                int maxx=-1,id;
                for(int j=1;j<=3;j++){
                    if(j==a[i].num){
                        continue;
                    }
                    if(aa[t.name][j]>maxx&&k[j]+1<=n/2){
                        maxx=aa[t.name][j];
                        id=j;
                    }
                }
                if(ans-aa[t.name][t.num]+maxx+a[i].x>ans){
                    ans=ans-aa[t.name][t.num]+maxx+a[i].x;
                    q[a[i].num].pop();
                    q[id].push({maxx,t.name,id});
                    q[a[i].num].push({a[i].x,a[i].name,a[i].num});
                    k[id]++;
                    vis[a[i].name]=1;
                }

            }
            else {
                q[a[i].num].push({a[i].x,a[i].name,a[i].num});
                ans+=a[i].x;
                k[a[i].num]++;
                vis[a[i].name]=1;
            }
        }

        cout<<ans<<"\n";
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
