#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10;
long long n,a[N],ch=1,sumn;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n-2;i++){
        for(int j=n;j>=n-(3+i-1)+1;j--) ch*=j;
        for(int j=1;j<=3+i-1;j++)ch/=j;
        sumn+=ch;
        ch=1;
    }
    printf("%lld",sumn);
    return 0;
}
