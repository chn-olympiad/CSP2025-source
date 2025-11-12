#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=2147483647;
const ll LLINF=9223372036854775807;
int a[20];
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   string s;
   vector<int> v;
   cin >> s;
   int len=s.size();
   for(int i=0;i<len;i++){
    if('0'<=s[i] && s[i]<='9'){
        a[s[i]-'0']++;
    }
   }
   for(int i=9;i>=0;i--){
        for(int j=0;j<a[i];j++){
            cout << i;
        }
   }
   cout << endl;
}
