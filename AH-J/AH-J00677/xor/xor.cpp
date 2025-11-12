#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct itf{
    int l , r;
    bool operator < (const itf a)const{
        if(r != a.r) return r < a.r;
        return l < a.l;
    }
};
vector<itf> e;
int len;
int a[200010];
int s[200010];
int cnt;
int last;
int n , k;
int main(){
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    scanf("%d%d" , &n , &k);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d" , &a[i]);
        s[i] = s[i - 1] ^ a[i];
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            if((s[i] ^ s[j - 1]) == k) e.push_back((itf){j , i});
        }
    }
    len = e.size();
    sort(e.begin() , e.end());
    for(auto k : e){
        if(k.l > last){
            cnt++;
            last = k.r;
        }
    }
    printf("%d" , cnt);
    return 0;
}
