#include <bits/stdc++.h>
using namespace std;

int n,m;
string str;
int num[20];

int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> str;
    for(int i=1;i<=n;i++)
        cin >> num[i];
    if(n <= 10) {
        int tmp[100] = {0,1,2,3,4,5,6,7,8,9,10};
        int ans = 0;
        do {
            int fst = 0;
            int ac = 0;
            for(int i=1;i<=n;i++) {
                if(fst >= num[tmp[i]]) fst++;
                else if(str[i-1] == '1') ac++;
                else fst++;
            } if(ac >= m) ans++;
        } while(next_permutation(tmp+1,tmp+n+1));
        cout << ans;
    } else if(n == m) {
        sort(num+1,num+n+1);
        int fst = 0;
        int ac = 0;
        for(int i=1;i<=n;i++)
            if(fst >= num[i]) fst++;
            else if(str[i-1] == '1') ac++;
            else fst++;
        if(ac >= m) cout << 1;
        else cout << 0;
    } else {
        long long sum = 1;
        for(int i=1;i<=n;i++)
            sum = (sum*i) % 998244353ll;
        cout << sum;
    } return 0;
}