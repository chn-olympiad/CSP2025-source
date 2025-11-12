#include <iostream>
#include <cstring>


int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    int numbers[10]={0};
    std::string s;
    std::cin >> s;
    int count;
    for (int i = 0; i < s.length(); i++) {
        if ('0' <= s[i] <= '9') {
            numbers[s[i]-'0']++;
        }
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < numbers[i]; j++) {
            std::cout << i;
        }
    }
    
    return 0;
}