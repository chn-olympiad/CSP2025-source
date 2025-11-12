#include<bits/stdc++.h>
using namespace std;
int b[10000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    getline(cin,a);
    long long sum=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            b[sum]=a[i]-48;
            sum++;
        }
    }
    for(int i=0;i<sum;i++)
    {
        for(int j=0;j<sum;j++)
        {
            if(b[j]<b[j+1])
            {
                int c=b[j];
                b[j]=b[j+1];
                b[j+1]=c;
            }
        }
    }
    for(int i=0;i<sum;i++)
    {
        cout<<b[i];
    }
    return 0;
}
