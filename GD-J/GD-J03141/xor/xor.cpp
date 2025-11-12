#include <bits/stdc++.h>
using namespace std;
vector<int> f;
unordered_set<int> g;
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
    int n, k;
    cin >> n >> k;
    f.resize(n+1);
    f[0] = 0;
    for(int i = 1;i <= n;i++){
        cin >> f[i];
    }
    for(int i = 1;i <= n;i++){
        if(g.count(i))continue;
        for(int j = 0;i+j<=n;j++){
            int a = f[i];
            for(int k = 1;k <= j;k++){
                a ^= f[i+k];
            }
            if(a == k) {
                for(int k = 0;k <= j;k++){
                    g.insert(i+k);
                }
                ans++;
            }

        }
    }
    cout << ans;
}
