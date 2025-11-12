#include <bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[5000050];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == k) cnt++;
    }
    cout << cnt;
    return 0;
}
