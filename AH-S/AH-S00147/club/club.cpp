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

int t;
void run();
int main(){
    redirected_io_to_file("club.in","club.out");
    input(t);
    for(int i=1;i<=t;i++){
        run();
    }
    flush();
    return 0;
}
/*
struct prefer{
    int i,c;
};
bool prefer_cmp(const prefer& lhs,const prefer& rhs){
    return lhs.c>rhs.c;
}
struct member{
    prefer p[4];
};
member m[N];
std::pair<int,int> buf[N];
bool vis[N];
int order[6][3]={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
int get_max_c(int layer,int *sum){
    int ans=0;
    for(int id=1;id<=3;id++){
            int len=0;
            for(int i=1;i<=n;i++){
                member& cur=m[i];
                if(vis[i]){
                    continue;
                }
                if(cur.p[layer].i==id){
                    ++len;
                    int c=cur.p[layer].c;
                    buf[len]=std::pair<int,int>(i,c);
                }
            }
            if(len!=0){
                std::sort(buf+1,buf+len+1,[&](const std::pair<int,int>& lhs,const std::pair<int,int>& rhs){
                    return lhs.second>rhs.second;
                });
                int number=std::min(sum[id],len);
                sum[id]=sum[id]-number;
                for(int i=1;i<=number;i++){
                    vis[buf[i].first]=true;
                    ans+=buf[i].second;
                }
            }
        }
    return ans;
}
*/
const int N=100010;
int n;
int mem[N][4];
int dfs(int cur,int* ds){
    if(cur>n){
        return 0;
    }
    int ans=0;
    for(int i=1;i<=3;i++){
        if(ds[i]>0){
            --ds[i];
            ans=std::max(ans,dfs(cur+1,ds)+mem[cur][i]);
            ++ds[i];
        }
    }
    return ans;
}
void run(){
    /*
    prefer arr[4];
    arr[1].i=1;arr[2].i=2;arr[3].i=3;
    arr[1].c=2;arr[2].c=4;arr[3].c=6;
    std::sort(arr+1,arr+4,prefer_cmp);
    for(int i=1;i<=3;i++){
        print(arr[i].i," ");
    }
    */
    input(n);
    for(int i=1;i<=n;i++){
            /*
        m[i].p[1].i=1;
        m[i].p[2].i=2;
        m[i].p[3].i=3;
        input(m[i].p[1].c,m[i].p[2].c,m[i].p[3].c);
        std::sort(m[i].p+1,m[i].p+4,prefer_cmp);
        vis[i]=false;
        */
        input(mem[i][1],mem[i][2],mem[i][3]);
    }
    /*
    int ans=0;

    for(int o1=1;o1<=6;o1++){
    int sum[4],local_ans=0;
    sum[1]=sum[2]=sum[3]=n/2;
    for(int layer=1;layer<=3;layer++){

    }
    ans=std::max(ans,local_ans);
    }
    */
    int ds[4];
    ds[1]=ds[2]=ds[3]=n/2;
    print(dfs(1,ds),"\n");
}
