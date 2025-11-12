#include <bits/stdc++.h>
using namespace std;
struct student{
    int id,grade;
}a[10001];
int n,m;
bool cmp(student x,student y){
    return x.grade > y.grade;
}
int zw[101][101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n*m;i++){
        cin >> a[i].grade;
        a[i].id = i;
    }
    sort(a+1,a+n*m+1,cmp);
    int x = 1,y = 1,l = 1;
    for (int i = 1;i <= n*m;i++){
        zw[x][y] = a[i].id;
        if (a[i].id == 1){
            cout << y << " " << x;
            return 0;
        }
        if (x+1 > n && l == 1){
            y++;
            l = 0;
        }
        else if (x-1 <= 0 && l == 0){
            y++;
            l = 1;
        }
        else{
            if (l == 1) x++;
            else x--;
        }
    }
    return 0;
}
