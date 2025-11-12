#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct nd{
    int x,c,i;
    nd(int _x = 0,int _c = 0,int _i = 0){
        x = _x,c = _c,i = _i;
    }
    bool operator<(const nd &p)const{
        return c < p.c;
    }
}a[200010];
int ct[4];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        cin>>n;
        ct[1] = ct[2] = ct[3] = 0;
        for(int i = 1;i <= n;++i){
            int x[4];
            cin>>x[1]>>x[2]>>x[3];
            int mxi = 0;
            for(int j = 1;j <= 3;++j)
                if(!mxi || x[mxi] <= x[j])
                    mxi = j;
            int mx = max(max(x[1],x[2]),x[3]);
            int mp = 1e15 + 7;
            for(int j = 1;j <= 3;++j)
                if(j != mxi)mp = min(mp,mx - x[j]);
            a[i] = nd(mx,mp,mxi);
        }
        sort(a + 1,a + 1 + n);
        int num = 0;
        for(int i = 1;i <= n;++i){
            ++ct[a[i].i];
            num += a[i].x;
        }
        for(int i = 1;i <= n;++i)
            if(ct[a[i].i] > (n >> 1)){
                --ct[a[i].i];
                num -= a[i].c;
            }
        cout<<num<<'\n';
    }
    return 0;
}