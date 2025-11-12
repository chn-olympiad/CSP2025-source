#include <bits/stdc++.h>

using namespace std;

void out();
int bs(int target);
int find(int target);

int m, n, t, a, ai[105]{0};
int c, r;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= (n * m); i ++){
        scanf("%d", &ai[i]);
    }
    a = ai[1];
    sort(ai + 1, ai + 1 + n * m, greater<int>());
    t = find(a);//printf("%d\n", t);
    // c = (t % n == 0) ? (t / n) : (t / n + 1);//printf("%d\n", c);
    // r = (c % 2 == 0) ? (n - (t % n) + 1) : ((t % n == 0) ? n : (t % n));
    if (t % n == 0){
        c = t / n;
        if (t / n % 2 == 0){
            r = 1;
        }
        else {
            r = n;
        }
        // r = n;
        // c = t / n;
    }
    else {
        c = t / n + 1;
        if (c % 2 == 0){
            r = n - (t % n) + 1;
        }
        else {
            r = t % n;
        }
    }
    // if (t % n != 0){
    //     c = t / n + 1;
    // }
    // else {
    //     c = t / n;
    // }
    printf("%d %d\n", c, r);
    // out();
    return 0;
}

void out(){
    for (int i = 0; i < n * m; i ++){
        printf("%d ", ai[i]);
    }
    return;
}

/* lol
int bs(int target){
    int l = 1, r = n * m + 1, mid = l + (r - l) / 2;
    while (l <= r){
        if (ai[mid] == target)
            return mid;
        else if (ai[mid > target])
            l = mid + 1;
        else
            r = mid -1;
    }
    return -1;
}
*/

int find(int target){
    for (int i = 1; i <= (n * m); i ++){
        if (ai[i] == target)
            return i;
    }
    return -1;
}




// freopen("seat.in", "r", stdin);
// freopen("seat.out", "w", stdout);

// feropen("seat.in", "r", stdin);
// feropen("seat.out", "w", stdout);

// freopen("seat.in", "w", stdin);
// freopen("seat.out", "r", stdout);

// freopen("seat.in", "r", stdout);
// freopen("seat.out", "w", stdin);