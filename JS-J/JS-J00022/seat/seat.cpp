#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 105;
ll num[N],n,m;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
   cin >> n >> m;
   for(ll i = 1;i <= n * m;i++){
        cin >> num[i];
   }
   int op = num[1];
   sort(num + 1,num + 1 + n * m,cmp);
   for(ll i = 1;i <= n * m;i++){
        if(num[i] == op){
            op = i;
            break;
        }
   }
   ll r = op / n;
   ll c = op % n;
   if(c != 0)
        r++;
   cout << r << " ";
   if(c == 0 && r % 2 == 0){
        cout << 1 <<endl;
        return 0;
   }
   if(c == 0 && r % 2 == 1){
        cout << n <<endl;
        return 0;
   }
   if(r % 2 == 0){
        c = n + 1 - c;
   }
   cout << c << endl;
    return 0;
}
