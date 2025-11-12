#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int m,n;
    scanf("%d%d",&n,&m);
    int a[n+10];
    for(int i=1;i<=n;i++)
    {
        scanf("&d",&a[i]);
    }
    printf("%d",a[1]);
    return 0;
}
