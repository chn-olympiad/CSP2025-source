#include <bits/stdc++.h>

using namespace std;

long long n;
long long maxin;
long long lens[5001];
long long frontsum[5001];
long long mod = 998244353;

// 40% correct i guess, the bigest 2^20 ~= is passable,

// for any situtation, we only need to dfine take or not take current i base stick
long long dfs(long long i, long long s, long long m, long long l) {// i mean the index i, s mean the current sum, m mean the current max, l mean the current number of stick(only l > 3 is stable);
    if(i>n){
        // if(l>=3)(cout << s << " "<< m<<endl);
        return (l>=3?(s>2*m):0);
    }
    int sum = 0;
    if(l>=3){
        // cout << s << " "<< m<<endl;
        if((s+(frontsum[n]-frontsum[i-1])) <= 2*m){ // this mean the less can't form a polygon, so just break
            return 0;
        }
    }
    return (dfs(i+1,s+lens[i],max(m,lens[i]),l+1)%mod + dfs(i+1, s, m, l)%mod)%mod;
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);


    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> lens[i];

    }

    sort(lens, lens+n);
    for(int i=1;i<=n;i++){
        frontsum[i] = frontsum[i-1] + lens[i];
    }

    //because the range of n < 5000, just dfs, the max is n^2, and with some cut line;
    cout << dfs(1, 0, 0 ,0);


    return 0;
}
