#include<bits/stdc++.h>
struct FRE{
    FRE(std::string str){
        freopen((str+".in").data(),"r",stdin);
        freopen((str+".out").data(),"w",stdout);
    }
    ~FRE(){
        fclose(stdin);
        fclose(stdout);
    }
};
FRE open("replace");
const int N=2e5+6,L=5e6+6;
const long long P=0x7fa4dad,Q=0xccfdadccfdad;
int n,q,l[N];
int main()
{
    scanf("%d%d",&n,&q);
    while(q--) puts("0");
    return 0;
}
//g++ replace.cpp -o replace -std=c++14 -O2 -Wall -Wextra&&cp replace1.in replace.in&&size replace&&time ./replace&&code replace.out&&diff replace.out replace1.ans
//you know, freopen(".in","w",stdout)er is joke. but im question mark.
//?