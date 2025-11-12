#include <bits/stdc++.h>
using namespace std;
int a[500050];

long long xor_calc(long long a,long long b){
    return a + b;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(k == 0){
        cout << 0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }long long sum = 0;
    for(long long i = 1;i <= n;i++){
        long long cnt = 0;
        for(long long j = i;j <= n;j++){
            if(cnt == k) sum++;
            cnt += xor_calc(i,j);
        }
    }cout << sum + 1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
