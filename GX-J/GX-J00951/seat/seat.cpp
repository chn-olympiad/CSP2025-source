#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int ret=0;
    for(int i=1; i<=n*m; i++)
    {
        scanf("%d",&a[i]);
        if(i==1)
        {
            ret=a[i];
        }
    }
    sort(a+1,a+n*m+1);
    for(int i=n*m; i>=1; i--)
    {
        if(a[i]==ret)
        {
            ret=n*m-i+1;
            break;
        }
    }
    int l=ret/n;
    int r=ret%n;
    if(r==0)
    {
        printf("%d %d",l,n);
        return 0;
    }
    else
    {
        l++;
    }
    if(l%2==1)
    {
        printf("%d %d",l,r);
    }
    else
    {
        printf("%d %d",l,m-r+1);
    }
    return 0;
}
