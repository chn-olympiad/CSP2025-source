#include <bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
    int sc,tag;
}a[1000];
bool cmp(Node x,Node y){
    return x.sc > y.sc;
}
int x = 1,y = 1,p = 1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
   cin >> n >> m;
   for(int i = 1;i <= n * m;i ++ ){
       cin >> a[i].sc;
       a[i].tag = 0;
   }
   a[1].tag = 1;
   sort(a + 1,a + n * m + 1,cmp);
   for(int i = 1;i <= n * m;i ++ ){
        if(a[i].tag == 1){
            cout << y << " " << x << endl;
            break;
        }
        if(p == 1){
           x ++;
           if(x > n){
              y ++;
              x = n;
              p = 3 - p;
           }
        }
        else{
           x --;
           if(x < 1){
              y ++;
              x = 1;
              p = 3 - p;
           }
        }
   }
   return 0;
}
