#include<bits/stdc++.h>
using namespace std;
#define pq priority_queue<int,vector<int>,greater<int> >
#define ll long long
#define append(i) push_back(i)
#define endl "\n"
struct edge{
    int l,r;
};
inline bool cmp(edge &a,edge &b)
{
    return a.r < b.r;
}
const int N = 5e5+5;
int a[N],sum_xor[N];
vector<edge> ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    map<int,vector<int> > pos;
    pos[0].append(0);
    sum_xor[1] = a[1];
    pos[a[1]].push_back(1);
    for(int i = 2;i <= n;i ++){
        sum_xor[i] = sum_xor[i-1]^a[i];
        pos[sum_xor[i]].append(i);
    }
    int r = -1,l = -1,len = 0;
    for(int i = 0;i <= n;i ++)
    {
        int need = sum_xor[i]^k;
        auto it = upper_bound(pos[need].begin(),pos[need].end(),i);
        if(it != pos[need].end()){
            ans.push_back({i,*it});
        }
    }
    sort(ans.begin(),ans.end(),cmp);
     r = ans[0].r;int cnt = 1;
    for(int i = 1;i < ans.size();i ++)
    {
        if(ans[i].l < r) continue;
        cnt ++;
        r = ans[i].r;
    }
    cout << cnt <<endl;
}

