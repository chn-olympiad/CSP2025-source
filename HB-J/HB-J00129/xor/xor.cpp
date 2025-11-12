#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,k,a[500010],b[500010]={0},p=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]|b[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int q=b[j]-b[i-1];
            if(q==k) p++;
        }
    }
    printf("%d",p);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    return 0;
}
