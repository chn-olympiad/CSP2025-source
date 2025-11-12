#include<bits/stdc++.h>
using namespace std;
const int M=30000000;
int a[M];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long int c=0,l=1,t;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(s[i]-'0'==j)
            {
                a[l]=j;
                l++;
            }

        }
    }
    for(int i=1;i<=l;i++)
    {
        for(int j=i;j<=l-i;j++)
        {
                if(a[j]<a[j+1])
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
        }
    }
    for(int i=1;i<=l-1;i++)
    {
        cout<<a[i];
    }
    return 0;
}

