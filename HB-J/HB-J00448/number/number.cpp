#include <iostream>
#include <cstring>
using namespace std;
char a[1000005];
long long tong[10];

int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>a;
    for(int i=0;i<=strlen(a)-1;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            ++tong[a[i]-'0'];
        }
    }
    for(int i=9;i>=0;i--)
    {
        int j=1;
        for(;tong[i]>=1000;j+=1000)
        {
            if(j>tong[i])
            {
                j-=1000;
                break;
            }
            cout<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i;
        }
        for(;tong[i]>=100;j+=100)
        {
            if(j>tong[i])
            {
                j-=100;
                break;
            }
            cout<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i;
        }
        for(;tong[i]>=10;j+=10)
        {
            if(j>tong[i])
            {
                j-=10;
                break;
            }
            cout<<i<<i<<i<<i<<i<<i<<i<<i<<i<<i;
        }
        for(;j<=tong[i];j++)
        {
            cout<<i;
        }
    }

    return 0;
}
