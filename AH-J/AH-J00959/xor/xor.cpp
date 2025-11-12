#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,k;
int a[N];
int l[N],r[N],t = 0,maxnt = 0,lt = 0,rt = n + 1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i)
        cin >> a[i];
    for(int i = 1; i <= n; ++ i){
        int f = -1;
        for(int j = i;j <= n; ++ j){
            int tot = a[i];
            for(int k = i + 1; k <= j; ++ k){
                tot = (tot xor a[k]);
            }
            if(tot == k and f == -1)f = j;
        }
        if(f != -1)++ t,l[t] = i,r[t] = f;
    }
    int tmp1 = 0,tmp2 = 0;
    for(int i = 1; i <= t; ++ i){
        if(l[i] > lt)tmp1 ++,lt = r[i];
    }
    for(int i = 1; i <= t; ++ i){
        if(r[i] < rt)tmp2 ++,rt = l[i];
    }
    maxnt= max(tmp1,tmp2);
    cout << maxnt;
    return  0;
}
