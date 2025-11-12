#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int o=0;
    int a[n*m]={};
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int s=a[0];
    for(int d=0;d<n*m;d++)
    {
        for(int f=0;f<n*m;f++)
        {
            if(a[f]>a[f+1])
            {
                o=a[f];
                a[f]=a[f+1];
                a[f+1]=o;
            }
        }
    }

    for(int l=n*m;l>0;l--)
    {
        if(a[l]==s)
        {
            if(l<n)
            {
                cout<<n<<' '<<1;
                break;

            }
            else
            {
                cout<<l%n+1<<' ';
                cout<<(l/3)+2;
                break;
            }
        }
    }


    return 0;
}
