#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 115;
int a[N],n,m,mark;
bool cmp(int a,int b){ return a > b; }
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)
        cin >> a[i];
    mark = a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1,j = 1,r = 1;j <= n * m && i <= m;j++){
        if(r % m == 1 && r > m) i++,r = 1;
        if(a[j] == mark){
            if(i & 1) return cout << i << " " << r,0;
            else return cout << i << " " << n - r + 1,0;
        }
        r++;
    }
    return 0;
}
