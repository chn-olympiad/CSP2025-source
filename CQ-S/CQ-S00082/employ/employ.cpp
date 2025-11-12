#include<bits/stdc++.h>
const int mod=998244353;
const int N=505;
int n,m,c[N];
std::string s;
namespace Task_1_2{
    bool chk(){ return n<=10; }
    int p[15],ans;
    void work(){
        std::iota(p+1,p+n+1,1);
        do{
            int ps=0,fl=0;
            for(int i=1;i<=n;i++){
                if(s[i]=='0'||fl>=c[p[i]]) fl++;
                else ps++;
            }
            if(ps>=m) ans++;
        }while(std::next_permutation(p+1,p+n+1));
        std::cout<<ans;
    }
}
namespace Task_12_14{
    bool chk(){
        return m==1;
    }
    void work(){
        int fc=1;
        for(int i=1;i<n;i++) fc=1LL*fc*i%mod;
        
    }
}
namespace A{
    bool chk(){
        for(int i=1;i<=n;i++) if(s[i]!='1') return false;
        return true;
    }
    
    void work(){
        
    }
}
int main(){
//    freopen("D:/csps/down/employ/employ4.in","r",stdin);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr);
    std::cin>>n>>m>>s,s=' '+s;
    for(int i=1;i<=n;i++) std::cin>>c[i];
    if(Task_1_2::chk()) Task_1_2::work();
//    else if(Task_12_14::chk()) Task_12_14::work();
//    else if(A::chk()) A::work();
    return 0;
}

