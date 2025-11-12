#include <bits/stdc++.h>
#define int long long
using namespace std;
//14:46 solve T1
const int N = 1e5 + 10;

struct node{
    int x,y,z;
}a[N];

int n;

bool cmp(node n1,node n2){
    return n1.x - max(n1.y,n1.z) > n2.x - max(n2.y,n2.z);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T;cin >> T;
    while(T --){
        cin >> n;
        for(int i = 1;i <= n;i ++) cin >> a[i].x >>a[i].y >> a[i].z;
        int ans = 0,x = 0,y = 0,z = 0;
        for(int i = 1;i <= n;i ++){
                int p = max(max(a[i].x,a[i].y),a[i].z);
            ans += p;

            if(p == a[i].x) x ++;
        else if(p == a[i].y ) y ++;
        else z ++;
        }
        if(x <= n / 2 && y <= n / 2 && z <= n / 2){
            cout << ans << '\n';
            continue;
        }

        if(y > n / 2){
            for(int i = 1;i <= n;i ++) swap(a[i].x,a[i].y);
        }else if(z >n / 2){
            for(int i = 1;i <= n;i ++) swap(a[i].x,a[i].z);
        }
        sort(a + 1,a + n + 1,cmp);
        ans = 0;
        for(int i = 1;i <= n / 2;i ++){
            ans += a[i].x;
        }
        for(int i = n / 2 + 1;i <= n;i ++){
            ans += max(a[i].y,a[i].z);
        }
        cout << ans << '\n';

    }


    return 0;
}
