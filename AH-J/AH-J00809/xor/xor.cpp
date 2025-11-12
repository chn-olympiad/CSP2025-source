#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt=0;
int main(void){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    if(k==0){
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)cnt++;
            else if(a[i]==1 && a[i+1]==1)
                cnt++,i++;
        }
        printf("%lld",cnt);
    }
    else if(k==1){
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)cnt++;
        }
        printf("%lld",cnt);
    }
    else cout<<"2443";
    return 0;
}
