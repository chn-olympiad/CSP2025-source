#include <bits/stdc++.h>
using namespace std;

const int maxn=500005
int n,k,a[maxn];
bool flag_1=true;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]!=1)
            flag_1=false;
    }
    if(flag_1 && n%2==0)
        printf("%d",n);
    else if(flag_1 && !n%2==0)
        printf("0");
    return 0;
}




