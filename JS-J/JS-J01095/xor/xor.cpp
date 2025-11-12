#include <bits/stdc++.h>
using namespace std;

int n,k,cnt = 0,flag[500005] = {0};
long long a[500005],sum[500005];

int check(int start,int endding){
    int max_x = 0;
    if(endding - start <= 2){
        if(flag[start-1] == 1&&sum[endding] == k){
            return 1;
        }else if(sum[start-1] ^ sum[endding] == k){
            return 1;
        }
    }else{
        for(int i = start;i < endding;i++){
            int x = check(start,i) + check(i+1,endding);
            if(x > max_x){
                max_x = x;
            }
        }
        return max_x;
    }
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    flag[0] = 1;
    flag[n+1] = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == k){
            cnt++;
            flag[i] = 1;
        }
        if(flag[i-1] == 1){
            sum[i] = a[i];
        }else{
            sum[i] = sum[i-1] ^ a[i];
        }
    }
    for(int i = 1;i <= n;i++){
        int s,e;
        if(flag[i] == 1){
            s = i + 1;
        }
        if(flag[i-1] == 1){
            s = i;
        }
        if(flag[i+1] == 1){
            e = i;
            cnt += check(s,e);
        }
    }
    cout << cnt;
    return 0;
}
