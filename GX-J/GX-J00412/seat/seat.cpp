#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,rs,as;
    int sum=0,cnt=0,cat;
    int c,r;
    int a[111];
    cin>>n>>m;
    rs=n*m;
    for(int i=1;i<=rs;i++)
    {
        cin>>a[i];
    }
    as=a[1];
    sort(a+1,a+1+rs);
    for(int i=rs;i>=1;i--)
    {
        cat++;
        if(a[i]==as)
        {
            sum=cat;
            break;
        }
    }
    if(sum<=n)
    {
        c=1;
        r=sum;
    }
    else if(sum>n)
    {
     for(int i=1;i<=m;i++)
     {
        if(i%2==0)
        {
            for(int j=n;j>=1;j--)
            {
                cnt++;
                if(cnt==sum)
                {
                    c=i;
                    r=j;
                    break;
                }
            }
        }
        else if(i%2!=0)
        {
            for(int j=1;j<=n;j++)
            {
                cnt++;
                if(cnt==sum)
                {
                    c=i;
                    r=j;
                    break;
                }
            }
        }
     }
    }
    cout<<c<<' '<<r;
    return 0;
}
