#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, R;
int a[1003];
bool cmp(int x, int y){
    return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 0;i < n*m;i++)
        cin >> a[i];
    R = a[0];
    int cnt = 0;
    sort(a, a+n*m, cmp);
    for(int i = 0;i < m;i++){
        if(i%2 == 0)
            for(int j = 0;j < n;j++)
                if(a[cnt++] == R){
                    cout << i+1 << ' ' << j+1 << '\n';
                    return 0;
                }

        if(i%2 == 1)
            for(int j = n-1;j >= 0;j--)
                if(a[cnt++] == R){
                    cout << i+1 << ' ' << j+1 << '\n';
                    return 0;
                }
    }
    return 0;
}
