#include<bits/stdc++.h>
using namespace std;
int a[5009];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,maxn=0,sum;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        if(a[i]>maxn)
        {
            maxn = a[i];
        }
    }
    if(n<=3)
    {
        if(sum>=(maxn*2))
        {
            printf("%d",1);
        }else{
            printf("%d",0);
        }
    }else{

        printf("%d",max(0,n-2));
    }
    return 0;

}
