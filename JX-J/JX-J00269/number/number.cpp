#include"iostream"
#include"string.h"
#include"vector"
#include"algorithm"
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    std::string s;
    std::cin>>s;
    std::vector<int> v;
    for(auto i:s){
        if(i>='0'&&i<='9'){
            v.push_back((int)i-'0');
        }
    }
    std::sort(v.begin(),v.end(),cmp);
    for(auto i:v){
        std::cout<<i;
    }
    return 0;
}
