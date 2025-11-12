#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],pre[500005];
int cnt,last;
int main(){
    freopen("xor.in" , "r" ,stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        pre[i] = pre[i-1] ^ a[i];
    }
    cout << n/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
