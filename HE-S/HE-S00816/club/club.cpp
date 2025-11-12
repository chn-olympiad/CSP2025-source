#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
template<typename T>inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while (ch <'0' || ch >'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch <='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
const int maxn = 1e5+5;
int T,n;
struct node{
    ll w;int id;
    bool operator < (const node &y) const{
        return w < y.w;
    }
};
priority_queue<node> q01,q02,q10,q12,q20,q21;
int bel[maxn];
int a[maxn][3];
int siz0,siz1,siz2;
ll ans = 0;
inline void init() {
    ans = siz0 = siz1 = siz2 = 0;
//    q01 = q02 = q10 = q12 = q20 = q21 = {};
	while (!q01.empty()) q01.pop();
	while (!q02.empty()) q02.pop();
	while (!q10.empty()) q10.pop();
	while (!q12.empty()) q12.pop();
	while (!q20.empty()) q20.pop();
	while (!q21.empty()) q21.pop();
    for (int i = 1; i <= n; i++) bel[i] = -1,a[i][0] = a[i][1] = a[i][2] = 0;
}

int main () {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    read(T);
    while (T--) {
        read(n);
        init();
        for (int i = 1; i <= n; i++) {
            read(a[i][0]),read(a[i][1]),read(a[i][2]);
            int max1=max({a[i][0],a[i][1],a[i][2]});
            int mid;
            if (a[i][0]==max1) {
            	if (a[i][1]>a[i][2]) mid = a[i][1];
            	else mid = a[i][2];
			}else if(a[i][1]==max1) {
				if (a[i][0]>a[i][2]) mid = a[i][0];
				else mid = a[i][2];
			}else{
				if (a[i][0]>a[i][1]) mid = a[i][0];
				else mid = a[i][1];
			}
            bool flag = false;
            if (a[i][0]==max1) {
                if (siz0<n/2) {
                    ans += a[i][0];
                    bel[i] = 0;
                    ++siz0;
                    flag = true;
                    q01.push({a[i][1]-a[i][0],i});
                    q02.push({a[i][2]-a[i][0],i});//0能放就直接放
                }else{
                    if (q01.top().w>=q02.top().w) {
                        if (a[i][0]+q01.top().w>=mid) {//
                            ans += a[i][0]+q01.top().w;
                            int id = q01.top().id;
                            bel[i] = 0;
                            flag = true;
                            q01.pop();
                            q01.push({a[i][1]-a[i][0],i});
                            q02.push({a[i][2]-a[i][0],i});
                            q10.push({a[id][0]-a[id][1],id});
                            q12.push({a[id][2]-a[id][1],id});
                            bel[id] = 1;
                            siz1++;
                        }
                    }else if (a[i][0]+q02.top().w>=mid) {//
                        ans += a[i][0]+q02.top().w;
                        int id = q02.top().id;
                        bel[i] = 0;
                        flag = true;
                        q02.pop();
                        q01.push({a[i][1]-a[i][0],i});
                        q02.push({a[i][2]-a[i][0],i});
                        q20.push({a[id][0]-a[id][2],id});
                        q21.push({a[id][1]-a[id][2],id});
                        bel[id] = 2;
                        siz2++;
                    }
                    if (!flag) {
                        if (a[i][1]==mid) {
                            ans += a[i][1];
                            bel[i] = 1;
                            q10.push({a[i][0]-a[i][1],i});
                            q12.push({a[i][2]-a[i][1],i});
                            siz1++;
                        }else{
                            ans += a[i][2];
                            bel[i] = 2;
                            q20.push({a[i][0]-a[i][2],i});
                            q21.push({a[i][1]-a[i][2],i});
                            siz2++;
                        }
                    }
                }
            }else if (a[i][1]==max1) {
                if (siz1<n/2) {
                    ans += a[i][1];
                    bel[i] = 1;
                    ++siz1;
                    flag = true;
                    q10.push({a[i][0]-a[i][1],i});
                    q12.push({a[i][2]-a[i][1],i});//1能放就直接放
                }else{
                    if (q10.top().w>=q12.top().w) {
                        if (a[i][1]+q10.top().w>=mid) {//
                            ans += a[i][1]+q10.top().w;
                            int id = q10.top().id;
                            bel[i] = 1;
                            flag = true;
                            q10.pop();
                            q10.push({a[i][0]-a[i][1],i});
                            q12.push({a[i][2]-a[i][1],i});
                            q01.push({a[id][1]-a[id][0],id});
                            q02.push({a[id][2]-a[id][0],id});
                            bel[id] = 0;
                            siz0++;
                        }
                    }else if (a[i][1]+q12.top().w>=mid) {//
                        ans += a[i][1]+q12.top().w;
                        int id = q12.top().id;
                        bel[i] = 1;
                        flag = true;
                        q12.pop();
                        q10.push({a[i][0]-a[i][1],i});
                        q12.push({a[i][2]-a[i][1],i});
                        q20.push({a[id][0]-a[id][2],id});
                        q21.push({a[id][1]-a[id][2],id});
                        bel[id] = 2;
                        siz2++;
                    }
                    if (!flag) {
                        if (a[i][0]==mid) {
                            ans += a[i][0];
                            bel[i] = 0;
                            q01.push({a[i][1]-a[i][0],i});
                            q02.push({a[i][2]-a[i][0],i});
                            siz0++;
                        }else{
                            ans += a[i][2];
                            bel[i] = 2;
                            q20.push({a[i][0]-a[i][2],i});
                            q21.push({a[i][1]-a[i][2],i});
                            siz2++;
                        }
                    }
                }
            }else{
                if (siz2<n/2) {
                    ans += a[i][2];
                    bel[i] = 2;
                    ++siz2;
                    flag = true;
                    q20.push({a[i][0]-a[i][2],i});
                    q21.push({a[i][1]-a[i][2],i});//2能放就直接放
                }else{
                    if (q20.top().w>=q21.top().w) {
                        if (a[i][2]+q20.top().w>=mid) {//
                            ans += a[i][2]+q20.top().w;
                            int id = q20.top().id;
                            bel[i] = 2;
                            flag = true;
                            q20.pop();
                            q20.push({a[i][0]-a[i][2],i});
                            q21.push({a[i][1]-a[i][2],i});
                            q01.push({a[id][1]-a[id][0],id});
                            q02.push({a[id][2]-a[id][0],id});
                            bel[id] = 0;
                            siz0++;
                        }
                    }else if (a[i][2]+q21.top().w>=mid) {//
                        ans += a[i][2]+q21.top().w;
                        int id = q21.top().id;
                        bel[i] = 2;
                        flag = true;
                        q21.pop();
                        q20.push({a[i][0]-a[i][2],i});
                        q21.push({a[i][1]-a[i][2],i});
                        q10.push({a[id][0]-a[id][1],id});
                        q21.push({a[id][2]-a[id][1],id});
                        bel[id] = 1;
                        siz1++;
                    }
                    if (!flag) {
                        if (a[i][0]==mid) {
                            ans += a[i][0];
                            bel[i] = 0;
                            q01.push({a[i][1]-a[i][0],i});
                            q02.push({a[i][2]-a[i][0],i});
                            siz0++;
                        }else{
                            ans += a[i][1];
                            bel[i] = 1;
                            q10.push({a[i][0]-a[i][1],i});
                            q12.push({a[i][2]-a[i][1],i});
                            siz1++;
                        }
                    }
                }
            }
            while (!q01.empty()&&bel[q01.top().id]!=0) q01.pop();
            while (!q02.empty()&&bel[q02.top().id]!=0) q02.pop();
            while (!q10.empty()&&bel[q10.top().id]!=1) q10.pop();
            while (!q12.empty()&&bel[q12.top().id]!=1) q12.pop();
            while (!q20.empty()&&bel[q20.top().id]!=2) q20.pop();
            while (!q21.empty()&&bel[q21.top().id]!=2) q21.pop();
        }
        printf("%lld\n",ans);
    }
    return 0;
}
