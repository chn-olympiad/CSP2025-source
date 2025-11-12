#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,a[n],b[n*n],m=-1,q=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]+b[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int l=b[j]-b[i-1];
            for(int k=i;k<=j;k++) m=max(m,a[k]);
            if(l>2*m) q++;
        }
    }
    printf("%d",q);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    return 0;
}
