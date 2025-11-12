#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin >> t;
    while(t--){
        int n,a[100005] = { },b[100005] = { },c[100005] = { },l;
        bool flaga = true,flagb = true;
        cin >> n;
        l = n / 2;
        for(int i = 1; i <= n; i++){
            cin >>a[i] >>b[i] >> c[i];
            if(b[i] != 0 || c[i] != 0)flaga = false;
            if(c[i] != 0)flagb = false;
        }
        if(flaga){
            sort(a+1,a+n+1,cmp);
            int ans = 0;
            for(int i = 1; i <= l; i++){
                ans += a[i];
            }
            cout << ans <<endl;
        }
    }
    return 0;
}
