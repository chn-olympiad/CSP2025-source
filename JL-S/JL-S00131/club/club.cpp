#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;

const int N = 1e5 +10;
int T;
int n;
PII a[N][5];
struct node{
    int id,x,y,z;
    bool operator < (const node &ret) const{
        if(x == ret.x) return a[id][z + 1].first < a[ret.id][ret.z +1].first;
        else return x < ret.x;
    }
};
int sum[5];
int ans;
priority_queue<node> que;

bool cmp(PII x,PII y){ return x.first > y.first; }

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans = 0;
        for(int i = 1;i <= n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            a[i][1] = {x,1},a[i][2] = {y,2},a[i][3] = {z,3};
            sort(a[i] + 1,a[i] + 3 + 1,cmp);
            ans += a[i][2].first;
            que.push({i,a[i][1].first - a[i][2].first,a[i][1].second,1});
        }
        sum[1] = sum[2] = sum[3] = 0;
        while(que.size()){
            node now = que.top();
            que.pop();
            if(sum[now.y] == n / 2) sum[a[now.id][2].second]++;
            else{
                ans += now.x;
                sum[now.y]++;
            }
        }
        cout<<ans<<endl;
    }
}
