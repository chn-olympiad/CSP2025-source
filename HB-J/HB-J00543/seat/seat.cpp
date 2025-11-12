#include <bits/stdc++.h>
using namespace std;

int a[1001];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    scanf("%d %d",&n,&m);
    int total=n*m;
    for(int i=0;i<total;i++)
    {
        scanf("%d",&a[i]);
    }
    int r=a[0];
    sort(a,a+total,cmp);
    int flag=0;
    while(a[flag]!=r)
    {
        flag++;
    }
    flag++;
    if(flag%n==0)
    {
        cout << flag/n << " ";
        if((flag/n)%2==0)
        {
            cout << 1;
        }
        else
        {
            cout << n;
        }
        return 0;
    }
    else
    {
        cout << flag/n+1;
    }
    if((flag/n)%2==0)
    {
        cout << " " << flag%n;
    }
    else
    {
        cout << " " << n-flag%n+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
