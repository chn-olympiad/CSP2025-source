#include <bits/stdc++.h>
using namespace std;
long long cnt=0,cn1=0,cn2=0,cn3=0,l=0,f=-1;

struct lclub
{
    int c1,c2,c3;
}a[100010];

bool cmp(lclub a,lclub b)
{
    if (a.c1 < b.c1) {
        return 1;
    } else if (a.c1 > b.c1) {
        return 0;
    } else {
        if (a.c2 < b.c2) {
            return 1;
        } else if (a.c2 > b.c2) {
            return 0;
        } else {
            if (a.c3 < b.c3) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

void dfs(int n)
{
    //骗分
    int f2=-1;
    for (int i=0;i<n;i++) {
        if (a[i].c1 != 0) {
            f2=1;
            break;
        }
    }
    for (int i=0;i<n;i++) {
        if (a[i].c3 != 0) {
            f2=3 ;
            break;
        }
    }
    if (f2 == -1) {
        for (int i=n-1;i>=n/2;i--) {
            cnt+=a[i].c2;
        }
        return;
    }
    f2=-1;
    for (int i=0;i<n;i++) {
        if (a[i].c1 != 0) {
            f2=1;
            break;
        }
    }
    for (int i=0;i<n;i++) {
        if (a[i].c2 != 0) {
            f2=3 ;
            break;
        }
    }
    if (f2 == -1) {
        for (int i=n-1;i>=n/2;i--) {
            cnt+=a[i].c3;
        }
        return;
    }
    f2=-1;
    for (int i=0;i<n;i++) {
        if (a[i].c2 != 0) {
            f2=1;
            break;
        }
    }
    for (int i=0;i<n;i++) {
        if (a[i].c3 != 0) {
            f2=3 ;
            break;
        }
    }
    if (f2 == -1) {
        for (int i=n-1;i>=n/2;i--) {
            cnt+=a[i].c1;
        }
        return;
    }
    //到这




    if (l >= n) {
        return;
    }
    for (int i=l;i<n;i++) {
        if (f != 1 && a[i].c1 > a[i].c2) {
            if (a[i].c1 > a[i].c3) {
                cn1++;
                cnt+=a[i].c1;
            } else if (f != 3) {
                cn3++;
                cnt+=a[i].c3;
            } else {
                cn2++;
                cnt+=a[i].c2;
            }
        } else {
            if (f != 2 && a[i].c2 > a[i].c3) {
                cn2++;
                cnt+=a[i].c2;
            } else if (f != 3) {
                cn3++;
                cnt+=a[i].c3;
            } else {
                cn1++;
                cnt+=a[i].c1;
            }
        }
        l=i;
        if (cn1 > n/2 || cn2 > n/2 || cn3 > n/2) {
            if (cn1 > n/2) {
                cn1--;
                f=1;
                cnt-=a[l].c1;
            } else if (cn2 > n/2) {
                cn2--;
                f=2;
                cnt-=a[l].c2;
            } else if (cn3 > n/2) {
                cn3--;
                f=3;
                cnt-=a[l].c3;
            }
            dfs(n);
        }
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> a[i].c1 >> a[i].c2 >> a[i].c3;
        }
        sort(a,a+n,cmp);
        dfs(n);
        cout << cnt << endl;
        cnt=0,cn1=0,cn2=0,cn3=0,l=0,f=-1;
    }
}
