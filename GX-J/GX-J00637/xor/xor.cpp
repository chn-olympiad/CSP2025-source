#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin >>n;
    int k;
    cin >>k;
    int num[n];
    for(int i=0;i<=n-1;i++)
    {
        cin >>num[i];
    }
    int sum=0;
    if(k==1)
    {
        for(int i=0;i<=n-1;i++)
        {
            if(num[i])
            {
                sum++;
            }
        }
    }
    if(k==0)
    {
        for(int i=0;i<=n-1;i++)
        {
            bool a=0;
            if(num[i])
            {
                if(a)
                {
                    sum++;
                    a=0;
                }
                else
                {
                    a=1;
                }
            }
            else
            {
                sum++;
            }
        }
    }
    cout <<sum;
}
