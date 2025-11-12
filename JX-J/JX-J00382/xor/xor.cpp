#include <stdio.h>
#include <vector>
using namespace std;

int n, k, w, an = 0;
bool a = true;
vector<int> arr;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w);
        if (w > 1) a = false;
        arr.push_back(w);
    }
    if (k == 0) {
        printf("1");
        return 0;
    }
    if (k <= 1 && a) {
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == 1) an++;
        printf("%d", an);
        return 0;
    }
    return 0;
}
