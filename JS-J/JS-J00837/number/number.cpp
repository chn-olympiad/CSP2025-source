#include<bits/stdc++.h>
using namespace std;
//#define int long long

const int N = 1e6 + 5;
string s;
int num[N],cnt;
string ans;
bool cmp(int x,int y){
    return x > y;
}

signed main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   cin >> s;
   for(int i = 0;i < s.size();i++){
       if(s[i] >= '0' && s[i] <= '9'){
           num[++cnt] = int(s[i] - '0');
       }
   }
   sort(num + 1,num + 1 + cnt,cmp);
   for(int i = 1;i <= cnt;i++){
       ans += char(num[i] + '0');
   }
   cout << ans << endl;
   return 0;
}
