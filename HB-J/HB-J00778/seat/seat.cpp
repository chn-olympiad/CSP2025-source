#include<iostream>
using namespace std;
int n,m,a[1000]={};
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=n*m; i++)
    {
        cin >> a[i];
    }
    int x=a[1];
    for(int i=1; i<=n*m; i++)
    {
        for(int j=i; j<=n*m; j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    //for(int i=1; i<=n*m; i++)
    //{
        //if((i-1)%n==0)
        //{
            //int b[20]={};
            //for(int j=i; j<=i-1+n; j++)
            //{
              //  b[j]=a[j];
            //}
            //int x=0;
            //for(int j=i-1+n; j<=i; j++)
            //{
            //    x++;
          //      a[j]=b[x];
        //    }
      //  }
    //}
    //for(int i=1; i<=n*m; i++)
    //{
        //cout << a[i] << " ";
        //if(i%n==0)
        //{
        //    cout << endl;
      //  }
    //}
    int s=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            s++;
            if(a[s]==x)
            {
                cout << i << " " << j;
            }
        }
    }
    return 0;
}
