#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    std::string s;
    std::cin >> s;

    std::vector<short> numbers;
    for(auto v:s){
        if(v >= '0' && v <= '9'){
            numbers.push_back(v-'0');
        }
    }

    std::sort(numbers.begin(), numbers.end(), [](int a, int b){return a>b;});

    if(*numbers.begin() == 0){
        std::cout << 0 << std::endl;
    }else{
        for(auto v:numbers){
            std::cout << v;
        }
        std::cout << std::endl;
    }

    return 0;
}
