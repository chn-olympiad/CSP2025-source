#include<bits/stdc++.h>
using namespace std;
int b[150];
int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    for(int i = 0;i < n*m;++i){
        cin >> b[i];
    }
    int tmp = b[0];
    sort(b , b + n*m);
    int s = n * m - 1;
    int p = n;
    for(int i = 1;i <= m;++i){
        for(int j = 1;j <= n;++j){
            if(i % 2 == 1){
                if(b[s] == tmp){
                    cout << i << " " << j;
                    return 0;
                }
                --s;
            }else{
                if(b[s] == tmp) {
                    cout << i << ' ' << p;
                    return 0;
                }
                s--;
                p--;
            }

        }
        p = n;
    }
    return 0;
}

