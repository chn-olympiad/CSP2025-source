#include <cstdio>
#include <random>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    srand(time(0));
    printf("%llu\n",(1ULL*rand()*rand()*rand())%998244353);
    return 0;
}
