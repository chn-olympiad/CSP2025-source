#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int n,k,ans,a[N];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    int num = 0;
    for (int i = 1;i <= n;i++){
        if (i == 1 || num == 0){
            num = a[i];
        }else{
            num = num ^ a[i];
        }
        if (num == k) {
            ans++;
            num = 0;
        }
    }
    cout << ans;
    return 0;
}
