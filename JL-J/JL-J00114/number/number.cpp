#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000+19;
int a[maxn];

int main(){
   string s;
   cin >> s;
   int cnt = 0, ans = 0;
   for(int i = 0; i < s.size(); i++){
       if(s[i] >= '0' && s[i] <= '9'){
           cnt++;
           a[cnt] = (s[i] - '0');
       }
   }
   sort(a+1, a+cnt+1);
   string k = "";
   for(int i = cnt; i >= 1; i--){
     k += (a[i] + '0');
   }
   for(int i = 0; i < s.size(); i++){
       if(k[i] != '0'){
        cout << k;
        return 0;
       }
   }
   cout << 0;
   return 0;
}
