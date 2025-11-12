#include <bits/stdc++.h>
using namespace std;
int a[1145140];
int n,m;
int f(int x)
{
    if((x/n)%2==0)
    {
        while((x-1)%n==0)
        {
            x--;
        }
        return x;
    }
    while(x%n==0)
    {
        x++;
    }
    return x;
}
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int ta=0;
    cin >>n >>m;
    for(int i=1;i<=n*m;i++)
    {
        cin >>a[i];
        if(i==1) ta=a[i];
    }
    sort(a+1,a+1+(n*m),cmp);
    if(a[1]==ta)
    {
        cout <<1 <<" " <<1;
        return 0;
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==ta)
        {
            if((i-1)%n==0 || i%n==0)
            {
                cout <<(int)(ceil(1.0*i/n)) <<" ";
                if(i%(n*2)==0 || (i-1)%(2*n)==0)
                {
                    cout <<1;
                }
                else
                {
                    cout <<n;
                }
            }
            else
            {
                cout <<abs(f(i)-i) <<' ' <<i/n;
            }
            return 0;
        }
        else
            continue;
    }
    return 0;
}
