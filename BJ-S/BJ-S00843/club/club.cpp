# include<bits/stdc++.h>
# define int long long
# define endl "\n"
using namespace std;
const int maxn=2e5+5;
int t, n, a[maxn][5], c[maxn], b[5], cnt=0, ans=0;
priority_queue<int> q;
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n; cnt=0; ans=0;
        while(!q.empty()) q.pop();
        memset(b, 0, sizeof(b));
        for(int i=1; i<=n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
        for(int i=1; i<=n; i++) {
            if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) {
                c[i]=1, b[1]++;
            } else if(a[i][2]>=a[i][3] && a[i][2]>=a[i][1]) {
                c[i]=2, b[2]++;
            } else {
                c[i]=3, b[3]++;
            }
            ans+=a[i][c[i]];
        }
        if(b[1]<=n/2 && b[2]<=n/2 && b[3]<=n/2) {
            cout << ans << endl;
        } else {
            if(b[1]>n/2) {
                for(int i=1; i<=n; i++) {
                    if(c[i]!=1) continue ;
                    if(a[i][2]<a[i][3]) {
                        q.push(a[i][3]-a[i][1]);
                    } else {
                        q.push(a[i][2]-a[i][1]);
                    }
                }
                for(int i=n/2+1; i<=b[1]; i++) {
                    int t=q.top(); q.pop();
                    ans+=t;
                }
                cout << ans << endl;
            } else if(b[2]>n/2) {
                for(int i=1; i<=n; i++) {
                    if(c[i]!=2) continue ;
                    if(a[i][1]<a[i][3]) {
                        q.push(a[i][3]-a[i][2]);
                    } else {
                        q.push(a[i][1]-a[i][2]);
                    }
                }
                for(int i=n/2+1; i<=b[2]; i++) {
                    int t=q.top(); q.pop();
                    ans+=t;
                }
                cout << ans << endl;
            } else {
                for(int i=1; i<=n; i++) {
                    if(c[i]!=3) continue ;
                    if(a[i][1]<a[i][2]) {
                        q.push(a[i][2]-a[i][3]);
                    } else {
                        q.push(a[i][1]-a[i][3]);
                    }
                }
                for(int i=n/2+1; i<=b[3]; i++) {
                    int t=q.top(); q.pop();
                    ans+=t;
                }
                cout << ans << endl;
            }

        }
    }
    fclose(stdin); fclose(stdout);
	return 0;
}
