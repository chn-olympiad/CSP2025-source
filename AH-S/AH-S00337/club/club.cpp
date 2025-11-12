//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<queue>
//#define p pair<int,p1>
//#define p1 pair<int,int>
//#define ss second
//#define ff first
//#define m second
//#define b first
//
//using namespace std;
//int t,n,ans;
////pair<int,mm>
//priority_queue<p>q;//满意度和 p1
//vector<p1> g[100005][5];// 部门 满意度
//int v[5];
//int dis[100005][5];
//int dij(int x,int s){
//    memset(dis,-0x3f,sizeof(dis));
//    memset(v,0,sizeof(v));
//    v[s]++;
//    dis[x][s]=0;
//    q.push({0,{x,s}});
//    while(!q.empty()){
//        p u=q.top();
//        q.pop();
//        if(u.ff<dis[u.ss.m][u.ss.b]) continue;
//        for(int i=0;i<g[u.ss.m][u.ss.b].size();i++){
//            p1 to=g[u.ss.m][u.ss.b][i];
//            if(v[to.b]<n/2&&dis[to.m][to.b]<to.m+u.ff){
//                v[to.b]++;
//                dis[to.m][to.b]=to.m+u.ff;
//                q.push({to.m+u.ff,{to.b,to.m}});
//            }
//        }
//    }
//
//    return max(dis[n][1],max(dis[n][2],dis[n][3]));
//}
//int main(){
//    freopen("club.in","r",stdin);
//    freopen("club.out","w",stdout);
//    cin>>t;
//    while(t--){
//        cin>>n;
//        for(int i=1,x,y,z;i<=n;i++){
//            cin>>x>>y>>z;
//            g[i-1][1].push_back({1,x});
//            g[i-1][2].push_back({1,x});
//            g[i-1][3].push_back({1,x});
//            g[i-1][1].push_back({2,y});
//            g[i-1][2].push_back({2,y});
//            g[i-1][3].push_back({2,y});
//            g[i-1][1].push_back({3,z});
//            g[i-1][2].push_back({3,z});
//            g[i-1][3].push_back({3,z});
//        }
//        int x=dij(1,1),y=dij(1,2),z=dij(1,3);
//        cout<<max(x,max(y,z))<<"\n";
//    }
//    return 0;
//}
///*
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
//
//3^16=129140163
//*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long t,n,a[100005][5],ccc;
long long ans=-0x3f3f3f3f;
int vis[5];
int f(int x,long long sum){
    if(x==n+1){
        ans=max(sum,ans);
    }
    for(int i=1;i<=3;i++){
        if(vis[i]<n/2){
            vis[i]++;
            f(x+1,sum+a[x][i]);
            vis[i]--;
        }
    }
}
int g(int x,long long sum){
    if(x==n+1){
        ans=max(sum,ans);
    }
    for(int i=1;i<=2;i++){
        if(vis[i]<n/2){
            vis[i]++;
            f(x+1,sum+a[x][i]);
            vis[i]--;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][3]==0){
                ccc++;
            }
        }
        if(ccc==n){
            g(1,0);
        }else{
            f(1,0);
        }

        cout<<ans<<"\n";
        ans=0;
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
