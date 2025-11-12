#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T;
int n;
int num[4];
struct club{
    int id,val;
};
bool cmp(club a,club b){
    return a.val>b.val;
}
struct node{
    club c[4];
    void so(){
        sort(c+1,c+1+3,cmp);
        return ;
    }
};
bool cmpp(node a,node b){
    return (bool)(a.c[1].val>b.c[1].val);
}
node a[N];
priority_queue<int> pq[4];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while(T--){
        for(int i=1;i<=3;i++){
            while(!pq[i].empty()){
                pq[i].pop();
            }
        }
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i].c[1].val;
            cin >> a[i].c[2].val;
            cin >> a[i].c[3].val;
            a[i].c[1].id=1;
            a[i].c[2].id=2;
            a[i].c[3].id=3;
            a[i].so();
        }
        int ans=0;
        sort(a+1,a+1+n,cmpp);
        num[1]=num[2]=num[3]=0;
        for(int i=1;i<=n;i++){
            num[a[i].c[1].id]++;
            pq[a[i].c[1].id].push(-(a[i].c[1].val-a[i].c[2].val));
            ans+=a[i].c[1].val;
        }
        for(int i=1;i<=3;i++){
            while(num[i]>n/2){
                num[i]--;
                ans+=pq[i].top();
                pq[i].pop();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}