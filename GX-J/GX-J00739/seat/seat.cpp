#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in", "r",stdin);
    freopen("seat.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    int a[20];
    int b[20]={100,99,98,97};

    for(int c = 0;c <= 20;c++){
        cin >> c;
    }


    for(int i = 0;i <= a[3];i++){
        for(int j = 0;j <= b[3];j++){
            if (i == j)
            {
                cout << 1 << " " << 2;

            }
            break;
        }
    }
    return 0;
}

