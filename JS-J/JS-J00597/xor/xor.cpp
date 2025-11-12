#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+1;
int n,k,num[N],num1 = 0,num0=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    scanf("%d%d",&n,&k);
    for (int i = 1;i <= n;i++){
        scanf("%d",&num[i]);
        if (!num[i]) num0++;
    }
    num1 =n-num0;
    if (k == 0){
        cout << num0 << '\n';
    }
    else{
        cout << num1 << '\n';
    }
    return 0;
}
