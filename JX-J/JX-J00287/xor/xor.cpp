#include<iostream>
using namespace std;

long long n,k;
const int M = 5e5 + 10;
long long num[M];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int a = 0;
    for(int i = 1;i<=n;i++){
        cin>>num[i];
        if(num[i] == 1) a++;
    }
    int cnt = 1,ans = 0;
    while(cnt <= n){
        long long x = num[cnt];
        if(k == 1){
            cout<<a;
            return 0;
        }
        if(x == k){
            ans++;
            continue;
        }
        int m = 1;
        while(x == num[cnt]){
            m++;
            cnt++;
            if(m == 2) break;
        }
        if(cnt<=n) ans++;
    //    cout<<cnt<<" ";
        cnt++;
    }
    cout<<ans;
    return 0;
}
