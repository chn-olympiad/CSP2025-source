#include <bits/stdc++.h>
using namespace std;
int n, t;
int a[100007][5];
struct node{
    int num, a, b, c;
};
queue<node> q;
int ans = 0;
int vis[107][107][107];
bool flagA, flagB;
int flag[100007];
bool h(int a, int b){
    return a > b;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for(int g = 1; g <= t; g ++){
        cin >> n;
        memset(vis, -0x3f, sizeof(vis));
        ans = 0;
        flagA = true, flagB = true;
        for(int i = 1; i <= n; i ++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][2] != 0)flagA = false;
            if(a[i][3] != 0)flagB = false;
        }
        if(flagA){
            for(int i = 1; i <= n; i ++){
                flag[i] = a[i][1];
            }
            sort(flag + 1, flag + 1 + n, h);
            for(int i = 1; i <= n/2; i ++){
                ans += flag[i];
            }
            cout <<ans << endl;
            continue;
        }
        q.push((node){a[1][1],1,0,0});
        q.push((node){a[1][2],0,1,0});
        q.push((node){a[1][3],0,0,1});
        while(!q.empty()){
            //cout<<"size="<<q.size()<<endl;
            int num = q.front().num;
            int ar[3], pos;
            ar[1] = q.front().a;
            ar[2] = q.front().b;
            ar[3] = q.front().c;
            pos = ar[1] + ar[2] + ar[3];
            q.pop();
            //cout<<" num = "<<num<<" pos="<<pos<<" "<<ar[1]<<" "<<ar[2]<<" "<<ar[3]<<endl;
            if(pos == n){
                ans = max(ans, num);
                //cout<<"  ans="<<ans<<endl;
                //cout<<" num = "<<num<<" pos="<<pos<<" "<<ar[1]<<" "<<ar[2]<<" "<<ar[3]<<endl;

                continue;
            }
            //if(vis[ar[1]][ar[2]][ar[3]]>=num)continue;
            //vis[ar[1]][ar[2]][ar[3]] = num;
            for(int i = 1; i <= 3; i ++){
                if(ar[i] + 1 > n / 2)continue;
                ar[i]++;
                q.push((node){num + a[pos + 1][i],ar[1],ar[2],ar[3]});
                ar[i]--;
            }
        }
        cout<<ans<< endl;
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

18
4
13
*/
