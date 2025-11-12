#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,js=0,l,h;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&a);
    for(int i=1;i<n*m;i++)
    {
        scanf("%d",&b);
        if(b>a)
            js++;
    }
    js++;
    if(js%n!=0)
        l=js/n+1;
    else  
        l=js/n;
    h=js-(l-1)*n;
    if(l&1)
        printf("%d %d",l,h);
    else  
        printf("%d %d",l,n-h+1);
    return 0;
}