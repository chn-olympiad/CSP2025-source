#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N=1e5+10;
int T,n;

struct z{
    pair<int,int> x[3];
};
struct z a[N];
int cmp(
pair<int,int> a,
pair<int,int> b){
    return a.first>b.first;
}
int cmp2(
struct z a,
struct z b){
    // int delta_a1=2*a.x[0].first-a.x[1].first-a.x[2].first;
    // int delta_a2=2*a.x[1].first-a.x[2].first-a.x[0].first;
    // int delta_a3=2*a.x[2].first-a.x[1].first-a.x[0].first;
    // int delta_b1=2*b.x[0].first-b.x[1].first-b.x[2].first;
    // int delta_b2=2*b.x[1].first-b.x[2].first-b.x[0].first;
    // int delta_b3=2*b.x[2].first-b.x[1].first-b.x[0].first;
    int delta_a1=a.x[0].first-a.x[1].first;
    int delta_a2=a.x[1].first;
    int delta_a3=0;
    int delta_b1=b.x[0].first-b.x[1].first;
    int delta_b2=b.x[1].first;
    int delta_b3=0;
    if(delta_a1==delta_b1){
        if(delta_a2==delta_b2){
            return delta_a3>delta_b3;
        }
        return delta_a2>delta_b2;
    }
    return delta_a1>delta_b1;
    return 1;
}
int submit[5];
int res;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        submit[0]=0;
        submit[1]=0;
        submit[2]=0;
        submit[3]=0;
        res=0;
        cin >> n;
        // cout << endl;
        for(int i=1;i<=n;i++){
            cin >> a[i].x[0].first>> a[i].x[1].first >> a[i].x[2].first;
            int zx = min( a[i].x[0].first, min(a[i].x[1].first, a[i].x[2].first));
            a[i].x[0].first -= zx;
            a[i].x[1].first -= zx;
            a[i].x[2].first -= zx;
            res+=zx;
            a[i].x[0].second=1;
            a[i].x[1].second=2;
            a[i].x[2].second=3;
            // cout << a[i].x[0].first <<" "<<
            // a[i].x[1].first<<" "<<
            // a[i].x[2].first << endl;
        }
        for(int i=1;i<=n;i++){
            sort(a[i].x,a[i].x+3,cmp);
        }
        sort(a+1,a+n+1,cmp2);
        for(int i=1;i<=n;i++){
            if(submit[a[i].x[0].second]<n/2){
                submit[a[i].x[0].second]++;
                res+=a[i].x[0].first;
                continue;
            }
            if(submit[a[i].x[1].second]<n/2){
                submit[a[i].x[1].second]++;
                res+=a[i].x[1].first;
                continue;
            }
            if(submit[a[i].x[2].second]<n/2){
                submit[a[i].x[2].second]++;
                res+=a[i].x[2].first;
                continue;
            }
        }
        cout << res << '\n';
    }
}