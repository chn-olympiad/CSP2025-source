#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+109;
int a[maxn];
int main(){
    int t;
    cin >> t;
    long long sum1 = 0, ax = 0, sum2 = 0, bx = 0, sum3 = 0, cx = 0;
    while(t--){
       int n;
       cin >> n;
       int cnt = n;
       while(n--){
           int a, b, c;
           cin >> a >> b >> c;
           int mx = max(a, b);
           int ans = max(mx, c);
           if(ans == a && ax <= cnt/2){
                ax++;
               sum1 += ans;
           }else if (ans == b && bx <= cnt/2){
               bx++;
               sum2 += ans;
           }else if(ans == c && cx <= cnt/2){
               cx++;
               sum3 += ans;
           }
       }
       cout << sum1 + sum2 + sum3 << endl;
       sum1 = 0, sum2 = 0, sum3 = 0;
    }
    return 0;
}
