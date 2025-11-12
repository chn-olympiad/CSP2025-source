#include <bits/stdc++.h>
using namespace std;
//------
int n,k,a[500005],c[500005],cnt;
//------
int dd(int i){
    for(int j = i;j<=n;j++)
            if(a[j]==(a[i-1]^k))
                return j;
    return 0x7f7f7f7f;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    a[0] = 0;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
}
    for(int i = 1;i<=n;i++){a[i] = (a[i]^a[(i-1)]);}
    memset(c,0x7f,sizeof(c));
    for(int i = 1;i<=n;i++){
        c[i] = dd(i);
    }
    for(int i = n;i>=1;i--){
        c[i] = min(c[i],c[i+1]);}
    int t=1;
    while(true){
        if(t>n){ break;}
        cnt++;
        t = c[t];
    }
    cout << cnt-1;
    return 0;
}
