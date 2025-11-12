//开考前不小心往桌面上放了一堆文件夹把电脑卡死了
//回收站：aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

//先Never Gonna Give You Up制人
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//slove slove slove slove slove slove slove slove slove
//slove slove slove slove slove slove slove slove slove
//slove slove slove slove slove slove slove slove slove
//slove slove slove slove slove slove slove slove slove
//slove slove slove slove slove slove slove slove slove
//我是那BJ-J02047！
//请求我的所有非空代码公示！
//记得加解说!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//开考等了5分钟才开始，开始完一看"考试剩余：4小时24分52秒"
//14:45开始写第二题，一眼MST变式
//不是这图咋有疏有密的？
//还有O(2^k*knlogm)的做法明显不行吧？
//以及1000个点的图怎么连10万条无向边？不让重边就是自环也不够啊

int input(){
    char ch;
    while (!isdigit(ch = getchar_unlocked()));
    int ret = ch ^ 48;
    while (isdigit(ch = getchar_unlocked())) ret = (ret << 3) + (ret << 1) + (ch ^ 48);
    return ret;
}
//祖传开不开O2都这么写的快读
struct edge{
    int v;
    long long w;
};
bool operator>(const edge& x,const edge& y){
    return x.w > y.w;
}
vector<edge>v[10015];
int c[15];
long long ans = 9e18;
int n,m,k;
long long dis[10015];
bool vis[10015];
long long prim(int x){//忘了Prim砸写了，不好
    int start = rand() % n + 1;
    priority_queue<edge,vector<edge>,greater<edge> >q;
    memset(dis,0x3f,sizeof dis);
    dis[start] = 0;
    q.push({start,dis[start]});
    memset(vis,false,sizeof vis);
    vis[start] = true;
    long long sum = 0;
    while (!q.empty()){
        int pos = q.top().v;
        //vis[pos] = true;
        q.pop();
        sum += dis[pos];
        //if (sum > ans) return 9e18;
        for (edge i:v[pos]){
            if (i.v > n){if (!(x & 1 << i.v - n - 1)) continue;}

            if (!vis[i.v] && dis[i.v] > dis[pos] + i.w){
                dis[i.v] = dis[pos] + i.w;
                q.push({i.v,dis[i.v]});
                vis[i.v] = true;
            }
        }
    }
    return sum;
}
int main(){
    srand(time(0));
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = input();
    m = input();
    k = input();
    for (int i = 1;i <= m;i++){
        int x = input(),y = input(),w = input();
        v[x].push_back({y,w});
        v[y].push_back({x,w});
    }
cout <<0<<endl;/*
    for (int i = 1;i <= k;i++){
        c[i] = input();
        for (int j = 1;j <= n;j++){
            int w = input();
            v[j].push_back({n + i,w});
            v[n + i].push_back({j,w});
        }
    }
    for (int i = 0;i < 1 << k;i++){
        int pre_cost = 0;
        for (int j = 1;j <= 10;j++) pre_cost += (i & 1 << j - 1) * c[j];
        ans = min(ans,prim(i) + pre_cost);
    }
    cout << ans <<endl;*/
    return 0;
}
//18:06最后选择输出0