#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000],p,b,c=1;
bool v(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    b=n*m;
    for(int i=0;i<b;i++)
    {
        cin>>a[i];
    }
    p=a[0];
    sort(a,a+b,v);
    for(int i=0;i<b;i++)
    {
        if(a[i]==p)
        {
            c+=i;
            break;
        }
    }
    int q=c/n;
    int w=c%n;
    if(q%2==0)
    {
        if(w>0)
        {
            cout<<q+1<<" "<<w;
        }
        else
        {
            cout<<q<<" "<<1;
        }
    }
    else
    {
        if(w>0)
        {
            cout<<q+1<<" "<<n-w+1;
        }
        else
        {
            cout<<q<<" "<<n;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
