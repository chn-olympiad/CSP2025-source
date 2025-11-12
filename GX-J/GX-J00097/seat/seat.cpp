#include<bits/stdc++.h>
using namespace std;
bool db(int a,int b)
{
  return a>b;

}

int main()
{
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int r=n*m,rf=0;
    int f[1001];
    for(int i=1;i<=r;i++)
    {
      cin>>f[i];
        rf=f[1];

    }
    sort(f+1,f+r+1,db);
    int rp=0,p=0;
    for(int i=1;i<=r;i++)
    {
      p++;
      if(f[i]==rf)
      {
        rp=p;


      }
    }
    int h=0;
    if(rp%n==0)
    {
        cout<<rp/n<<" ";

        h=rp/n;
    }
    else
    {
       cout<<rp/n+1<<" ";
        h=rp/n+1;
    }
    if(h%2==1)
    {
        if(rp%n==0)
        {
            cout<<n;


        }
        else
        {
             cout<<rp%n;

        }


    }
    else
    {
        if(rp%n!=0)
        {
                    cout<<n-rp%n+1;
        }
        else
        {
              cout<<1;
        }

    }
//cout<<endl;
//cout<<rp;
    return 0;
}
