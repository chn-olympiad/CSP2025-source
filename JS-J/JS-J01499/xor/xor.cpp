#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,k,a[N],xorsum[N],cnt = 0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k; xorsum[0] = 0;
    for (int i = 1;i<= n;i++){
        cin>>a[i];
        xorsum[i] = xorsum[i-1]^a[i];
    }
    for (int i = 1;i<= n;i++){
        for (int len = 1;len<= n;len++){
            if ((xorsum[i-1]^xorsum[i-1+len])== k){
                cnt++;
                i+= len-1;
                break;
            }
        }
    }cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
