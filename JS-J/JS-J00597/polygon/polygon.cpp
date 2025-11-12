#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const long long MO = 998244353;
long long ans = 0;
int n,le[N];
bool com(int a,int b){
    return a >= b;
}
void dfxsy(int m,int maxn,int sum,int num){
    if (m==n && num >=3){
        if (sum <= maxn*2) return;
        else{
            ans++;
            return;
        }
    }
    if (num >= 3){
        if (sum > maxn*2){
            ans++;
        }
    }
    for (int i = m+1;i <= n;i++){
        num++;
        dfxsy(i,max(maxn,le[i]),sum+le[i],num);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    scanf("%d",&n);
    for (int i = 1; i<=n;i++){
        scanf("%d",&le[i]);
    }
    sort(le+1,le+n+1,com);
    for (int i = 1;i <= n-2;i++){
        dfxsy(i,le[i],le[i],1);
    }
    cout << ans%MO<< '\n';//yu a!
    return 0;
}
