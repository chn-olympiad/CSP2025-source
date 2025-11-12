#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
int a[N];
bool p[N];
int main()
{
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    int n , k;
    cin >> n >> k;
    for(int i = 0;i < n; ++i){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0;i < n;++i){
        for(int j = i;j < n;++j){
            int tmp = 0;
            for(int m = i;m <= j;++m){
                tmp = a[m] ^ tmp;
            }
            if(tmp == k){
                int pd = 0;
                for(int m = i;m <= j;++m){
                    if(p[m] == 1){
                        pd = 1;
                        break;
                    }
                }
                if(pd == 0){
                    ans++;
                    for(int m = i;m <= j;++m){
                        p[m] = 1;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}

