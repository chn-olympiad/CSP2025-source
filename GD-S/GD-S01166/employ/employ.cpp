#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <bitset>

using namespace std;

constexpr int MOD = 998244353;

constexpr int N = 520;
constexpr int M = 520;

int n,m;
bitset<N> dif;
unsigned c[N];

int p[N];

int main(){
    (void)freopen("employ.in","r",stdin);
    (void)freopen("employ.out","w",stdout);

    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<n;++i){
        dif[i] = (s[i]=='1');
        p[i]=i;
    }
    for(int i=0;i<n;++i)cin>>c[i];


    uint64_t ans=0;
    do{
        uint64_t cnt=0,rej=0;

        for(int i=0;i<n;++i){
            // cout<<p[i]<<' ';
            if(c[p[i]]<=rej)++rej;
            else if(!dif[i])++rej;
            else ++cnt;
        }
        // cout<<" cnt: "<<cnt<<" rej: "<<rej<<'\n';
        if(cnt>=m)++ans;

    }while(next_permutation(p, p+n));

    cout<<ans%MOD<<'\n';


    fclose(stdin);
    fclose(stdout);
    return 0;
}