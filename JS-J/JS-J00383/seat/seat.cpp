#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n,m,x = 1,y = 1;

struct S{
    int data,id;
}a[N];

bool cmp(struct S a,struct S b){
    return a.data > b.data;
}

int main(){
    freopen("seat.in","r",stdin);
    freoprn("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++){
        cin >> a[i].data;
        a[i].id = i;
    }
    sort(a + 1,a + n * m + 1,cmp);
    for (int i = 1;i <= n * m;i++){
        if (a[i].id == 1){
            cout << x << ' ' << y << '\n';
            return 0;
        }
        if (x % 2 == 1) y++;
        else y--;
        if (y == 0){
            x++;
            y = 1;
        }
        if (y == m + 1){
            x++;
            y = m;
        }
    }
    return 0;
}
