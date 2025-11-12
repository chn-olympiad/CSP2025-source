#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int b[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum,peace,renp=0,renpp;
    cin>>n>>m;
    sum=n*m;
    for(int i=0;i<sum;i++)
    cin>>b[i];
    renpp=b[0];
    for(int i=0;i<sum;i++)
    {
       for(int x=i;x<sum;x++)
        {
        if(b[x]>=b[i])
            {
            peace=b[x];
            b[x]=b[i];
            b[i]=peace;
            }
        }
    }

    for(int i=0;i<sum;i++)
        if(b[i]==renpp)
        {
          renp=renp+i+1;
          break;
        }

    if(renp>n)
    {
        if(renp%n==0)
        {
            if((renp/n)%2==0)
                cout<<renp/n<<' '<<'1';
            else
                cout<<renp/n<<' '<<n;
        }
        else
            {
                if((renp/n+1)%2==0)
                cout<<renp/n+1<<' '<<n-renp%n+1;
                else
                    cout<<renp/n+1<<' '<<renp%n;
            }

    }
    else
        cout<<'1'<<' '<<renp;

    return 0;
}
