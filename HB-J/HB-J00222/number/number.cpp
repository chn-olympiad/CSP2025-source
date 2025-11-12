/*
1.to make the number the largest, need to use all the numbers
2.to make the number the largest, need to make a1a2a3... that a1>=a2>=a3>=...
3.if we only have 0, output 0;
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#define INIT std::ios::sync_with_stdio(false),\
    std::cin.tie(0),std::cout.tie(0);
namespace AC{
    #define ll long long
    std::string str;
    std::vector<int>v;
    inline bool isDigit(char x){
        return x>='0'&&x<='9';
    }
    void Init(),PreSolve(),Input(),Solve(),Answer(),ACit();
}
int main(){
    AC::ACit();
    return 0;
}
void AC::Init(){
    INIT;
    freopen("number.in" ,"r",stdin );
    freopen("number.out","w",stdout);
}
void AC::PreSolve(){}
void AC::Input(){
    std::cin>>str;
}
void AC::Solve(){
    for(char ch:str){
        if(isDigit(ch))
            v.push_back(ch-'0');
    }
    std::sort(v.begin(),v.end());
    std::reverse(v.begin(),v.end());
}
void AC::Answer(){
    for(auto x:v) std::cout<<x;
}
void AC::ACit(){
    Init();
    int T=1;
    //std::cin>>T;
    while(T--){
        PreSolve();
        Input();
        Solve();
        Answer();
    }
}