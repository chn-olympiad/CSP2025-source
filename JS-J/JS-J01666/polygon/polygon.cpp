#include<bits/stdc++.h>
using namespace std;
long long n , a[10005];
bool cmp(int x,int y){
    return x < y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long res = 0;
    for(int i = 3;i <= n;i++){
        long long maxn = a[i];
        long long tot = 0;
        for(int j = 1;j < i;j++){
            tot += a[j];
            if(tot > maxn)res++;
        }
        if(tot <= maxn)continue;
        int tot1 = tot;
        for(int j = 1;j < i;j++){
            tot -= a[j];
            if(tot > maxn)res++;
        }
        for(int j = 2;j < i;j++){
            int m = tot1;
            m -= a[j];
            if(m > maxn)res++;
        }
    }
    cout << res;
    return 0;
}
