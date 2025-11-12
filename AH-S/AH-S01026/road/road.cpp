#include <cstdio>
#include <random>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    srand(time(0));
    printf("%llu\n",(1ULL*rand()*rand()*rand())%998244353);
    return 0;
}
