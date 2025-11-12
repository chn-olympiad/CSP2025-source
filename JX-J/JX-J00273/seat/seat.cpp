#include<bits/stdc++.h>
using namespace std;
int a[110];
int cmp(int c,int b)
{
    return c>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m*n;i++)
    {
        cin>>a[i];
    }
    int t=a[1],x;
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==t)
        {
            x=i;
            break;
        }
    }
    if(x<=m)
    {
        cout<<1<<" "<<x;
    }
    else
    {
        if(x%m!=0)
        {
            cout<<x/m+1<<" ";
            if((x/m+1)%2==0)
            {
                int y=x%m;
                for(int i=m;i>=1;i--)
                {
                    int sum=0;
                    sum++;
                    if(sum==y)
                    {
                        cout<<i;
                        return 0;
                    }
                }
            }
            else
                cout<<x%m;
        }
    }
    return 0;
}
