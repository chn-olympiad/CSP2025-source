#include <bits/stdc++.h>
using namespace std;
int n , t;
int a1 , b1 , c1;
int a , b , c;
int aa[100010];
bool cmp(int a , int b){
    return a > b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int ans = 0;
    cin >> t;
    int xb = 1;
    while(t --){
        cin >> n;
        xb = 1;
        for(int i = 1;i <= n;i ++){
            cin >> a >> b >> c;
            if(b == 0 && c == 0){
                aa[xb] = a;
                xb ++;
                sort(aa + 1 , aa + xb + 1 , cmp);
            }
        }
        cout << aa[1] << endl;
    }
    return 0;
}
