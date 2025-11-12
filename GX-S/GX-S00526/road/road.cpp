#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int ret=0;
    for(int i=1; i<=n; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ret+=c;
    }
    for(int j=1; j<=k; j++)
    {
        int l,r;
        scanf("%d",&l);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&r);
        }
    }
    printf("%d",ret);
    return 0;
}
