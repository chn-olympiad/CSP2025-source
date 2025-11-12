#include<bits/stdc++.h>
using namespace std;
int t,n,a1,a2,a3,res;
short c[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int j=0;j<t;++j)
    {
        res=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d",&a1,&a2,&a3);
            res+=a2;
            c[i]=a1-a2;
        }
        sort(c,c+n);
        for(int i=n/2;i<n;++i)
        {
            res+=c[i];
        }
        printf("%d\n",res);
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
