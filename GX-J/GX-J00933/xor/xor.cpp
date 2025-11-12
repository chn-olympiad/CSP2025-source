#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    int n, k;
    int arr[500010];

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    cout << k;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
