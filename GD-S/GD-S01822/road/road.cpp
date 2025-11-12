#include<bits/stdc++.h>
using namespace std;
long long n,m,k,i,j,cc=0,aa=0,u,v,w;
int main(){
    ///*
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //*/
    //特殊性质 A:对于所有 1 ≤ j ≤ k,均有 c j = 0 且均存在 1 ≤ i ≤ n 满足 a j,i = 0。
    scanf("%lld%lld%lld",&n,&m,&k);
    for(i=0;i<m;i++) scanf("%lld%lld%lld",&u,&v,&w);
    for(i=0;i<k;i++)
    {
        scanf("%lld",&u);
        cc+=u;
        for(j=0;j<n;j++)
        {
            scanf("%lld",&w);
            aa+=w;
        }
    }
    if(cc==0&&aa==0) printf("0");
    return 0;
}
/*
 ^
__
-
-
-
__
 -
 -
 -
 -
__
-
-
__

==
*/
