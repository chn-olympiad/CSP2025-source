#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y)
{
    return x> y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<= n*m;i++) scanf("%d",&a[i]);
    int t = a[1];
    sort(a+1,a+n*m+1,cmp);
    int tmp ;
    for(int i = 1;i<= n*m;i++) if(t == a[i]) tmp = i;
    int c = tmp/n;
    if(tmp%n != 0) c++;
    if(c%2 == 1)
    {
        if(tmp%n ==0 ) printf("%d %d",c,n);
        else printf("%d %d",c,tmp%n);

    }
    else
    {
        if(tmp%n ==0) printf("%d %d",c,1);
        else printf("%d %d",c,n-tmp%n+1);
    }
    printf("\n");
    return 0;
}
