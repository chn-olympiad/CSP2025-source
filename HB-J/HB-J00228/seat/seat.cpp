#include <bits/stdc++.h>
#define I_AK_CSP return 0
#define fr(k,n) for(int i=k;i<=(n);i++)
using namespace std;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[114]={0};
    cin >> n >> m;
    fr(1,n*m){cin >> a[i];}
    int pos = 0;
    fr(1,n*m){
        if (a[i] > a[pos])pos = i;
    }
    int cnt = 0,r = 0;
    for (int i = 1;;){
        cnt ++;
        if (i % 2 == 1){
            if (r == n)i ++;
            else r ++;
        }
        else{
            if (r == 1)i ++;
            else r --;
        }
        if (cnt == pos){
            cout << i << ' ' << r;
            I_AK_CSP;
        }
    }
    I_AK_CSP;
}
