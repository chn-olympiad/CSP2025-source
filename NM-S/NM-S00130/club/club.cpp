#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[100001];
int b[100001];
int c[100001];
int ma;
int as,bs,cs;
long long ans = 0LL;

int solve(){
    if(as <= n/2 && bs <= n/2 && cs <= n/2){
        return 0;
    }
    if(as > n/2 && bs <= n/2 && cs <= n/2){
        int t = as - n/2;
        int mi = 1e9;
        int bc,id;
        while(t--){
            for(int i = 1;i <= n;i++){
                if(bs < n/2 && a[i] != -1 && b[i] != -1){
                    mi = min(mi,a[i] - b[i]);
                    if(a[i] - b[i] < mi) bc = 1,id = i;
                }
                if(cs < n/2 && a[i] != -1 && c[i] != -1){
                    mi = min(mi,a[i] - c[i]);
                    if(a[i] - c[i] < mi) bc = 2,id = i;
                }
            }
            if(id != 0){
                ans -= a[id] - 0LL;
                if(bc = 1) ans += b[id] + 0LL,b[id] = -1,a[id] = -1,bs++;
                if(bc = 2) ans += c[id] + 0LL,c[id] = -1,a[id] = -1,cs++;
            }
            mi = 1e9,id = 0;
        }
    }
    else if(as > n/2 && bs > n/2 && cs <= n/2){
        int t = (as - n/2) + (bs - n/2);
        int mi = 1e9;
        int ab;
        int id;
        while(t--){
            for(int i = 1;i <= n;i++){
                if(as > n/2 && a[i] != -1 && c[i] != -1){
                    mi = min(mi,a[i] - c[i]);
                    if(a[i] - c[i] < mi) ab = 1,id = i;
                }
                if(bs > n/2 && b[i] != -1 && c[i] != -1){
                    mi = min(mi,b[i] - c[i]);
                    if(b[i] - c[i] < mi) ab = 2,id = i;
                }
            }
            if(id != 0){
                if(ab = 1) ans -= a[id] - 0LL,ans += c[id] + 0LL,a[id] = -1,as--;
                if(ab = 2) ans -= b[id] - 0LL,ans += c[id] + 0LL,b[id] = -1,bs--;
            }
            mi = 1e9,c[id] = -1,id = 0;
        }
    }
    else if(as <= n/2 && bs > n/2 && cs <= n/2){
        int t = bs - n/2;
        int mi = 1e9;
        int ac,id;
        while(t--){
            for(int i = 1;i <= n;i++){
                if(as < n/2 && a[i] != -1 && b[i] != -1){
                    mi = min(mi,b[i] - a[i]);
                    if(b[i] - a[i] < mi) ac = 1,id = i;
                }
                if(cs < n/2 && b[i] != -1 && c[i] != -1){
                    mi = min(mi,b[i] - c[i]);
                    if(b[i] - c[i] < mi) ac = 2,id = i;
                }
            }
            if(id != 0){
                ans -= b[id] + 0LL;
                if(ac = 1) ans += a[id] + 0LL,a[id] = -1,b[id] = -1,as++;
                if(ac = 2) ans += c[id] + 0LL,c[id] = -1,b[id] = -1,cs++;
            }
            mi = 1e9,id = 0;
        }
    }
    else if(as <= n/2 && bs > n/2 && cs > n/2){
        int t = (cs - n/2) + (bs - n/2);
        int mi = 1e9;
        int bc;
        int id;
        while(t--){
            for(int i = 1;i <= n;i++){
                if(bs > n/2 && b[i] != -1 && a[i] != -1){
                    mi = min(mi,b[i] - a[i]);
                    if(b[i] - a[i] < mi) bc = 1,id = i;
                }
                if(cs > n/2 && c[i] != -1 && a[i] != -1){
                    mi = min(mi,c[i] - a[i]);
                    if(c[i] - a[i] < mi) bc = 2,id = i;
                }
            }
            if(id != 0){
                if(bc = 1) ans -= b[id] - 0LL,ans += a[id] + 0LL,b[id] = -1,bs--;
                if(bc = 2) ans -= c[id] - 0LL,ans += a[id] + 0LL,c[id] = -1,cs--;
            }
            mi = 1e9,a[id] = -1,id = 0;
        }
    }
    else if(as <= n/2 && bs <= n/2 && cs > n/2){
        int t = cs - n/2;
        int mi = 1e9;
        int ab,id;
        while(t--){
            for(int i = 1;i <= n;i++){
                if(as < n/2 && c[i] != -1 && a[i] != -1){
                    mi = min(mi,c[i] - a[i]);
                    if(c[i] - a[i] < mi) ab = 1,id = i;
                }
                if(bs < n/2 && c[i] != -1 && b[i] != -1){
                    mi = min(mi,c[i] - b[i]);
                    if(c[i] - b[i] < mi) ab = 2,id = i;
                }
            }
            if(id != 0){
                ans -= c[id] - 0LL;
                if(ab = 1) ans += a[id] + 0LL,a[id] = -1,as++;
                if(ab = 2) ans += b[id] + 0LL,b[id] = -1,bs++;
            }
            mi = 1e9,c[id] = -1,id = 0;
        }
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	scanf("%d",&T);
	for( ;T--; ){
        ans = 0LL,as = 0,bs = 0,cs = 0;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            ma = max(a[i],b[i]);
            ma = max(ma,c[i]);
            if(ma == a[i]) as++,ans += a[i] + 0LL;
            if(ma == b[i]) bs++,ans += b[i] + 0LL;
            if(ma == c[i]) cs++,ans += c[i] + 0LL;
        }
        solve();
        printf("%lld",ans);
	}
	return 0;
}
