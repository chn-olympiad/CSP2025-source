#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
string s;
int a[N + 5];
int k;
signed main() {
   freopen("number.in", "r", stdin);
   freopen("number.out", "w", stdout);
   cin >> s;
   for(int i = 0; i < s.size(); i ++){
      if(s[i] >= '0' && s[i] <= '9'){
         a[++ k] = s[i] - '0';
      }
   }
   sort(a + 1, a + 1 + k);
   for(int i = k; i >= 1; i --){
      cout << a[i];
   }
   cout << "\n";
   fclose(stdin);
   fclose(stdout);
   return 0;
}