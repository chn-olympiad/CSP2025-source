#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
char c[N];
 int a[N];
 long long de(int x){
    long long ans = 1;
    for(int i = 1; i <= x; i++){
        ans *= i;
        ans %= 998244353;
        }
    return ans;
 }
int main(){
 freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n , m;
    cin >> n >>m;
    string s1;
    cin >>s1;
    for(int i = 1; i <= n; i++)
    cin >> a[i];
    cout << de(n);
    return 0;

}
