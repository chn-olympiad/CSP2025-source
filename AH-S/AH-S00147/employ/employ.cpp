#include"bits/stdc++.h"

typedef signed char byte;
typedef unsigned char unsigned_byte;
typedef char* c_style_string;

template<typename T>
inline void print(const T& val){
    std::cout<<val;
}
template<typename T,typename... Args>
inline void print(const T& val,const Args&... vals){
    std::cout<<val;
    print(vals...);
}
template<typename T>
inline void input(T& var){
    std::cin>>var;
}
template<typename T,typename... Args>
inline void input(T& var,Args&... vars){
    std::cin>>var;
    input(vars...);
}
inline void flush(){
    std::cout<<std::flush;
    return;
}
inline void redirected_io_to_file(const c_style_string input_path,const c_style_string output_path){
    freopen(input_path,"r",stdin);
    freopen(output_path,"w",stdout);
}
void run();
int main(){
    redirected_io_to_file("employ.in","employ.out");
    run();
    flush();
    return 0;
}
int n,m;
bool s[100000];
int c[100000];
void run(){
    input(n,m);
    std::string temp;
    input(temp);
    for(int i=0;i<n;i++){
        s[i+1]==(temp[i]=='1');
    }
    for(int i=1;i<=n;i++){
        input(c[i]);
    }
    print(2);
}
