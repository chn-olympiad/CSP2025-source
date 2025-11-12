#include <bits/stdc++.h>
using namespace std;
int a[1010][5];
int main () {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int ret=0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            ret+=max(a[i][1],max(a[i][2],a[i][3]));
        }
        printf("%d\n",ret);
    }
}
