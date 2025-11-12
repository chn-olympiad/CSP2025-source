#include <iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[n*m]={0};
    for(int i=0;i<n*m;i++)
    {
        cin>>arr[i];
    }
    int R=arr[0];
    for(int i=0;i<n*m-1;i++)
    {
        for(int j=i+1;j<n*m;j++)
        {
            int a=arr[i];
            if(arr[i]<arr[j])
            {
                arr[i]=arr[j];
                arr[j]=a;
            }
        }
    }
    for(int i=0;i<m*n;i++)
    {
        if(arr[i]==R)
        {
            R=i+1;
        }
    }
    if(R%n==0)
    {
        if(R/n%2==0)
        {
            cout<<R/n<<' '<<1;
        }else
        {
            cout<<R/n<<' '<<n;
        }
    }else
    {
        if(R/n%2==0)
        {
            cout<<R/n+1<<' '<<R%n;
        }else
        {
            cout<<R/n+1<<' '<<n-R%n+1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
