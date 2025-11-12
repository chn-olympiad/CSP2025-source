#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N][3];
int len[3];

struct node {
    int v;
    bool operator < (const node x) const {
        return x.v < this->v;
    }
};

priority_queue<node>q[3];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) 
        for(int j = 0; j <= 2; ++j)
            cin >> a[i][j];
    int ansi = 0;
    for(int i = 1; i <= n; ++i) {
        int id = 0, maxi = 0, cmaxi = 0;
        for(int j = 0; j <= 2; ++j) {
            int nv = a[i][j];
            if(len[j] == n / 2)
                nv -= q[j].top().v;
            // if(i == 2 && j == 0) cerr << nv << " ";
            if(nv >= maxi)
                cmaxi = maxi, maxi = nv, id = j;
            else if(nv > cmaxi)
                cmaxi = nv;
        }
        // cerr << id << " ";
        // cerr << maxi << " " << cmaxi << "\n";
        ansi += maxi;
        if(len[id] == n / 2) {
            maxi += q[id].top().v;
            q[id].pop();
        }
        else
            ++len[id];
        q[id].push(node{maxi - cmaxi});
    }
    cout << ansi << "\n";
    for(int i = 0; i <= 2; ++i) {
        while(!q[i].empty())
            q[i].pop();
        len[i] = 0;
    }
}

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios :: sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
/*
都 2025 年了，我怎么还在打 CSP？
你说得对，但是代码请使用衡水体，不然会扣书写分。
写完 T1 不想写了，开摆休息，反正也没有获奖压力。
没有获奖压力为什么还要写题？
先写点废话，等会再写 OI 生涯回忆录好了。
应该没有人盒我吧？
froepen("club.in","r",stdin);//只是为了整活
还有什么活可以整呢，这次绝对是最后一次打 CSP 了。
为什么代码写一半没有过程分？为什么打个头文件没有公式分？
你说的对，但是今天是11.1，虽然没有任何关系但是还是想说
Subscribe to Technoblade 谢谢。
希望我没打错什么单词，打错了也只能说明我唐。
为什么不能提前交卷？
退一万步来讲，为什么不能带作业进考场写？
欸我为什么要写题？
你说得对，但请支持知更鸟谢谢喵。虽然今天不是星期日，但每一天都是星期日。
*/