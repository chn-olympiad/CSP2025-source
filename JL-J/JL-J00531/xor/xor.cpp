#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,k,a[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","r",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n==1) printf("0\n");
    else if(n%2==0) printf("%d\n",n/2);
    else printf("%d\n",(n-1)/2);
    return 0;
}
