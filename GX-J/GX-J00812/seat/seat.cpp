#include<iostream>
using namespace std;
int n,m,s,a[120],sum=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    s=a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>s) sum++;
    }

    if(sum>n&&sum%n!=0) printf("%d",(sum/n)+1);
    else if(sum>n&&sum%n==0) printf("%d",sum/n);
    else printf("%d",1);

    printf("%c",' ');

    if(sum<=n) printf("%d",sum);
    else if(sum%n!=0 && ((sum/n)+1)%2==0) printf("%d",n-(sum%n-1));
    else if(sum%n==0 && ((sum/n)%2==0)) printf("%d",1);
    else if(sum%n==0) printf("%d",n);
    else printf("%d",sum%n);
    return 0;
}
