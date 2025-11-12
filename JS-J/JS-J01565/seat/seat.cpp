#include <bits/stdc++.h>
using namespace std;
int a[120];// a is for in
int b[20][20];// b is for out;
int c[20][20];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;// n hang , m lie
    cin >> n >> m;
    for(int i = 1;i <= n * m;i ++)
    {
        cin >> a[i];
    }
    int R = a[1];

    sort(a + 1, a + 1 + n * m,cmp);

    /*for(int i = 1;i <= n * m;i ++)
    {
        cout << a[i]<<' ';
    }
    cout << "\n";*/
    int id = 0;
    for(int j = 1;j <= m;j ++)
    {
        for(int i = 1;i <= n;i ++)
        {
            id ++;
            c[i][j] = a[id];
        }
    }
    /*for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= m;j ++)
        {
            cout << c[i][j] <<" ";
        }
        cout << "\n";
    }*/
    for(int j = 1;j <= m;j ++)
    {
        for(int i = 1;i <= n;i ++)
        {
            if(j % 2 == 0){
                b[i][j] = c[n - i + 1][j];
            }
            else b[i][j] = c[i][j];
        }
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= m;j ++)
        {
            if(b[i][j] == R){
                cout << j << " " << i;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
