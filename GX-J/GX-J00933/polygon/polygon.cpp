#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    int n;
    int line = 0;
    int arr[5005];

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 3; i <= n; i++){
        for (int j = 1; j <= i; i++){
            int num[i];

            for (int k = 1; k <= i; k++)
                num[k] = k;

            for (int k = 1; k <= i; k++){
                int ans = 0;
                for (int k = 1; k <= i; k++)
                    ans += num[k];

                if (ans > num[i] * 2)
                    line++;

            }
        }
    }

    cout << line;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
