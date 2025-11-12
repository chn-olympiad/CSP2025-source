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
    redirected_io_to_file("replace.in","replace.out");
    run();
    flush();
    return 0;
}
const int N=200010;
std::pair<std::string,std::string> pairs[N];
void run(){
    int n,q;
    input(n,q);
    for(int i=1;i<=n;i++){
        std::string s1,s2;
        input(s1,s2);
        pairs[i]=std::pair<std::string,std::string>(s1,s2);
    }
    for(int i=1;i<=q;i++){
        std::string t1,t2;
        input(t1,t2);
        if(t1.size()!=t2.size()){
            print(0,"\n");
            continue;
        }
        int len=t1.size();
        int dif_begin=0,dif_end=0;
        for(int j=0;j<len;j++){
            if(t1[j]!=t2[j]){
                dif_begin=j;
                break;
            }
        }
        for(int j=len-1;j>=0;j--){
            if(t1[j]!=t2[j]){
                dif_end=j+1;
                break;
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            std::pair<std::string,std::string> p=pairs[j];
            int plen=p.first.size();
            if(plen>len){
                continue;
            }
            if(plen<dif_end-dif_begin){
                continue;
            }//plen>=dif_end-dif_begin;dif_end-plen<=dif_begin;
            int check_head_begin=std::max(dif_end-plen,0);
            int check_head_end=std::min(dif_begin,len-plen)+1;
            for(int k=check_head_begin;k<check_head_end;k++){
                std::string x,y,z;
                y=t1.substr(k,plen);
                if(y==p.first){
                    y=p.second;
                }
                else{
                    continue;
                }
                x=t1.substr(0,k);
                z=t1.substr(k+plen);
                if(x+y+z==t2){
                    ++ans;
                }
            }
        }
        print(ans,"\n");
    }
}
