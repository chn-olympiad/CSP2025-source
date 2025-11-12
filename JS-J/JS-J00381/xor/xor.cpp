#include<iostream>
using namespace std;
int main()
{
    int n,k,l=0,c=0,z=0;
    cin>>n>>k;
    int a[n]={0},b[n]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int j=z;j<=i;j++)
        {
            b[j]=b[j]^a[i];
            if(b[j]==k)
            {
                c++;
                z=j;
                break;
            }
        }
    }
    cout<<c;
    return 0;
}
