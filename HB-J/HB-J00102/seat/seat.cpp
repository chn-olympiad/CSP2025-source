#include <bits/stdc++.h>

using namespace std;

int n,m;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    int p,k=0;
    scanf("%d",&p);
    for(int i=1,tmp;i<=n*m-1;i++)
    {
        scanf("%d",&tmp);
        if(tmp>p)k++;
    }
    int r,c;
    c=k/n+1;
    k%=(2*n);
    if(k<n)r=k+1;
    else r=2*n-k;
    printf("%d %d",c,r);
}
