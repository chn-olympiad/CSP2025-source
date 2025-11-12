#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,sum=0;

void dfs(const vector<vector<ll>>& a,int index,int searched,ll sumed,int n) {
    if (index>n) {
        return;
    }

    for (int i=0;i<3;i++) {
        if (i!=searched) {

            sum=max(sum,sumed+a[index][i]);
            //if (sum > sumed+a[index][i]) {
             //   cout << index << ' ' << i << endl;
            //}
        }
    }

}

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i =0;i<t;i++) {
        int n;
        cin >> n;
        vector<vector<ll>> a(n+1,vector<ll>(3,0));
        for (int i=1;i<=n;i++) {
            for (int j=0;j<3;j++) {
                cin >> a[i][j];
            }
        }
        dfs(a,1,-1,0,n);
        cout << sum << endl;
        sum=0;


    }
    return 0;
}
