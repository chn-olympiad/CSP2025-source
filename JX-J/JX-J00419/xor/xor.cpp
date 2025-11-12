#include<bits/stdc++.h>

using namespace std;

long long all = 0;

long long a[500100];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cnt = 1;
    long long mx = -1;
    for(int i = 1; i <= n; i++){
        long long k;
        cin>>k;
        mx = max(mx,k);
        if(k == 1){
            all++;
        }else if(k == 0){
            a[cnt] = i;
            cnt++;
        }

    }
    int ans = n - all;
    for(int i = 1;i < cnt; i++){
        ans += (a[i] - a[i - 1] - 1) / 2;
    }
    if(m > mx){
        cout<<0;
    }else if(m == 1){
        cout<<all;
    }else if(m == 0){
        cout<<ans;
    }

    return 0;
}
