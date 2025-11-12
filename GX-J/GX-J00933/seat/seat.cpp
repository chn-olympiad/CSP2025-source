#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int m, n, a1, x;
    int arr[110] = {0};

    cin >> m >> n;

    for (int i = 1; i <= m*n; i++){
        cin >> arr[i];

        if (i == 1)
            a1 = arr[i];

        for (int j = i; j >= 2; j--){
                if (arr[j] >= arr[j-1])
                    swap(arr[j], arr[j-1]);
                else
                    break;
            }
    }

    for(int i = 1; i <= m*n; i++)
        if (arr[i] == a1){
            x = i;
            break;
        }

    int c = x / n + 1;
    int y = 0;

    if (c % 2 == 1){
        if (x % n == 0)
            y = n;
        else
            y = x % n;
    }
    else if (c % 2 == 0){
        if (x % n == 0)
            y = 1;
        else
            y = n + 1 - (x % n);
    }

    cout << c << ' ' << y;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
