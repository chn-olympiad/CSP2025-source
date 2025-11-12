#include<bits/stdc++.h>
using namespace std;
int book[100];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            book[a[i]-'0']++;
        }
    }
    int f=0;
    for(int i=9;i>=0;i--)
    {
        if(book[i]!=0&&i!=0)
        {
            f=1;
        }
        if(i!=0)
        {
            for(int j=0;j<book[i];j++)
            {
                cout<<i;
            }
        }
        else
        {
            if(f==1)
            {
                for(int j=0;j<book[i];j++)
                {
                    cout<<i;
                }
            }
            else
            {
                cout<<0;
            }
        }
    }
    return 0;
}
