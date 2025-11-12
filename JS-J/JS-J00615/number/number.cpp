#include <iostream>
#include <algorithm>

char str[13+(int)1e6], num[13+(int)1e6];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> str;
    int top=0;
    for(int i=0;str[i];i++) if(str[i] >= '0' && str[i] <= '9') num[top++]=str[i];
    std::sort(num, num+top, std::greater<char>());
    if(num[0]!='0') std::cout << num;
    else std::cout << 0;
}
