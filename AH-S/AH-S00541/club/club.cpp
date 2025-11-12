#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int T, n, m, ans, cnt[4];
int p[N], pid[N], num;
struct node{
    int val, id;
    bool operator <(const node &tmp){
        return val > tmp.val;
    }
};
struct element{
    node v[4];
}a[N];

inline ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
void Reset(){
    memset(cnt, 0 ,sizeof cnt);
    memset(p, 0 ,sizeof p);
    memset(pid, 0 ,sizeof pid);
    num = 0;
    ans = 0;

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T = read();
    while(T--){
        Reset();
        n = read();
        for(int i=1;i<=n;i++){
            a[i].v[1] = node{read(), 1};
            a[i].v[2] = node{read(), 2};
            a[i].v[3] = node{read(), 3};
            sort(a[i].v+1, a[i].v+4);
            cnt[a[i].v[1].id]++;
            ans += a[i].v[1].val;
        }
        int loc = 0;
        if(cnt[1] > n/2)loc = 1;
        if(cnt[2] > n/2)loc = 2;
        if(cnt[3] > n/2)loc = 3;
        if(loc == 0){cout << ans << endl;continue;}
        for(int i=1;i<=n;i++){
            if(a[i].v[1].id == loc){
                p[++num] = a[i].v[2].val - a[i].v[1].val;
                pid[num] = a[i].v[2].id;
            }
        }
        sort(p+1, p+num+1);
        for(int i=num;i>=num-cnt[loc]+n/2+1;i--){
            ans += p[i];
        }
        cout << ans << endl;
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


1
4
0 1 0
0 1 0
0 2 0
0 2 0

*/



