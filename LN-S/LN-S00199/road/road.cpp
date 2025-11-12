#include<bits/stdc++.h>
using namespace std;
struct edge{
    int s;
    int z;
    int v;
}e[1000001];
int l[11][100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,m,k;
    cin>>n>>m>>k;
    int ans1=0;
    int ans2=0;
    int zans=INT_MAX;
    for(int i=1;i<=m;i++){
        cin>>e[i].s>>e[i].z>>e[i].v;
        ans1+=e[i].v;
    }
    zans=min(ans1,zans);
    for(int i=1;i<=k;i++){
        ans2=0;
        for(int j=1;j<=n;j++){
            cin>>l[i][j];
            ans2+=l[i][j];
        }
        zans=min(zans,ans2);
    }
    cout<<zans<<endl;
    return 0;
}




































/*
这大概ia是我OI 生涯的最后一舞了，思来想去，还是写点东西吧
不管有没有人会看见这一切。
当我T1每出来，T2最短路写挂的时候，我已经明白了我的命运。
运气这次没有站到我这边，甚至可以说是站到了我的对立面。
但OI 就是这么残酷，一个字符，就会毁掉一整道题
我已无心成文，姑且想什么写什么吧
检查的时候突然发现自己的club竟然写成了clud
不知道某些地方是否还有想不到的细小错误
估分应该是过不了100，去年还是省一呢，今天却什么都没有剩下
今天只有残留的躯壳，可我的光辉岁月到底在哪里
今年已经是高一了，明年应该不会在见到我了
都说竞赛是入坑，所言不假，如果没有成绩，只能回去去走文化课
他人给了我很大的期望，我却无法回报给他们应有的结果
这分数大概是进不了NOIP了
还有6分钟
能平静的面对这一切也是一种勇气吧
到现在，终于明白了，为什么唯一的英雄主义是认清生活的真相后依然热爱生活
生活远比OI残酷，结果也更加难以让人接受
让我独自享受OI生涯的最后2分钟吧
就此别过吧，OI
仅已以上内容证明我曾来过
无名于2025/11/1
*/
