#include<bits/stdc++.h>
using namespace std;
int main()
{
    feopen("number.in","r",stdin);
    feopen("number.out","w",stdout);
    int b[100];
    int a;
    cin>>a;
    if(a<10)
    {
        cout<<a;
    }
    else
    {
        for(int i=1;i<=100;i++)
        {
            b[i]=a/10;
        }
        int num=0;
        int m=0;
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                if(b[i]>b[j])
                {
                    m=b[i];
                    b[i]=b[j];
                    b[j]=m;
                }
            }
        }
        for(int i=1;i<=100;i++)
        {
            num*=10;
            num+=b[i];
        }
        cout<<num;
    }
    return 0;
}
