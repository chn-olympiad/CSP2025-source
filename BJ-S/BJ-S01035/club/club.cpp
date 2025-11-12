#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <memory.h>

#define ll long long

using namespace std;

int stus[4],n,maxn;
bool book[114514];

struct t{
    int a,b,c;
};

vector<t> vec;

void dfs(int s,int now){
    if (s == n){
        maxn = max(maxn,now);
        return;
    }
    book[s] = 1;
    //cout << stus[1] << " " << n/2 << " " << s <<endl;
    if (stus[1] <= n/2-1){
        stus[1]++;
        dfs(s+1,now+vec[s].a);
        stus[1]--;
    }

    if (stus[2] <= n/2-1){
        stus[2]++;
        dfs(s+1,now+vec[s].b);
        stus[2]--;
    }

    if (stus[3] <= n/2-1){
        stus[3]++;
        dfs(s+1,now+vec[s].c);
        stus[3]--;
    }
}

int main()
{
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while (t--){
        vec.clear();
        maxn = -1;
        memset(book,0,sizeof(book));
        memset(stus,0,sizeof(stus));
        cin >> n;
        for (int i = 1; i <= n; i++){
            int a,b,c;
            cin >> a >> b >> c;
            vec.push_back({a,b,c});
        }
        dfs(0,0);
        cout << maxn << endl;
    }
    return 0;
}
