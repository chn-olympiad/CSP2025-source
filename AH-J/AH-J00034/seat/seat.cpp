#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum=0,s[200],a=0,b=0,c=0,d=0,w=0;
    cin>>n>>m;
    sum=n*m;
    for(int i=0;i<sum;i++)
    {
        cin>>s[i];
    }
    a=s[0];
    for(int i=0;i<sum-1;i++)
    {
        for(int l=0;i<sum-1;l++)
    {
        if(s[l]<s[l+1])
        {
            d=s[l];
            s[l]=s[l+1];
            s[l+1]=d;
        }

    }
    }

    for(int i=0;i<sum;i++)
    {
        w++;
        if(s[i]==a)
        {
            break;
        }
    }
    b=w-w%10;
    b=b/10;
    if(b==0)
        b++;
    c=w%10;
      cout<<b<<" "<<c;
      //2 2
      //99 100 97 98
      //101
    fclose(stdin);fclose(stdout);
    return 0;
}

