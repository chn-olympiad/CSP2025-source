#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int m, n, goal, ans, c, r;
    int arr[100];
    cin >> n >> m;
    for(int i = 0; i < n * m; i++){
        cin >> arr[i];
    }
    goal = arr[0];
    sort(arr, arr + n * m, cmp);

    for(int i = 0; i < n * m; i++){
        if(goal == arr[i]){
            ans = i;
            break;
        }
    }

    c = 1; r = 1;
    int y = 1;
    for(int i = 0; i < ans; i++){
        r += y;
        if(r > n || r < 1){
            c++;
            y *= -1;
            r += y;
        }
    }
    cout << c << ' ' << r;
    fclose(stdin); fclose(stdout);
}

