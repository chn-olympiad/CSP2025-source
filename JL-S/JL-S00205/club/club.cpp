#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
//struct go{
  //  int a[4];
//};
int s[5];
map<int, int> mp;
map<int, int> gh;
int a1[N], b1[N], c1[N];
int main() {

    int t;
    scanf("%d", &t);

    while(t --) {
        int n;
        scanf("%d", &n);
        long long cnt = 0;

        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= 3;j ++) {
                scanf("%d", &s[j]);
                mp[s[j]] = j;
            }
            int mx = max(s[1], max(s[2], s[3]));
            if(gh[mp[mx]] > n / 2) {
                for(auto i:gh) {

                }
            }
        }

    }

    return 0;
}
