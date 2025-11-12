#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen£¨"number.in","r",stdin£©;
    freopen("number.out","w",stdout);
    long long a,m=0,k;
    cin>>a;
    int arr[100000];
    while(a!=0)
    {
        arr[m]=a%10;
        m++;
        a/=10;

    }
    if(m=1)
    {
         cout<<arr[0];
         return 0;

    }

    for(int i=0;i<m;i++)
    {
        for(int j=i;j<m;j++)
        {
            if(arr[i]<arr[j])
            {
                k=arr[i];
                arr[i]=arr[j];
                arr[j]=k;
            }

        }

    }
    for(int i=0;i<m;i++)
    {
        cout<<arr[i];

    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
