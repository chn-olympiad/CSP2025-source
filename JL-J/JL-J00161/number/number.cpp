#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;

int n;
char str[N];
vector <int> num;

void inp() {
    scanf("%s", str + 1);
}

void work() {
    n = strlen(str + 1);

    for (int i = 1; i <= n; i ++ )
        if (isdigit(str[i]))
            num.push_back(str[i] - 48);
    
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());

    for (auto item : num)
        printf("%d", item);
    
    puts("");
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    
    inp();
    work();

    fclose(stdin);
    fclose(stdout);

    return 0;
}