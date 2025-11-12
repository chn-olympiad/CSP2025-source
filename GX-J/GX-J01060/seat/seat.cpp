#include <bits/stdc++.h>
using namespace std;
int a[100];
int cap(int a, int b){
    return a = 0;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    int c, r;
    int i, l;
    cin >> n >> m;
    cin >> c >> r;
    for(int i = 2;i <= m * n;i++)
    {
        cin >> m[i];
    }
    int a;
    for(int i = 1;i <= m;i++)
    {
        if(i == m){
            if(m == n)
            {
                c = l/n;
            }
            else
            {
                c = l/n + m;
            }
        }
    }
    cout << c << " " << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
