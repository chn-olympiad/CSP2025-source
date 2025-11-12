#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
string n;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    long long k=n.size();
    for(int i=0;i<n.size();i++)
    {
        if(n[i]=='0')
        {
            a[i+1]=0;
        }
        else if(n[i]=='1')
        {
            a[i+1]=1;
        }
        else if(n[i]=='2')
        {
            a[i+1]=2;
        }
        else if(n[i]=='3')
        {
            a[i+1]=3;
        }
        else if(n[i]=='4')
        {
            a[i+1]=4;
        }
        else if(n[i]=='5')
        {
            a[i+1]=5;
        }
        else if(n[i]=='6')
        {
            a[i+1]=6;
        }
        else if(n[i]=='7')
        {
            a[i+1]=7;
        }
        else if(n[i]=='8')
        {
            a[i+1]=8;
        }
        else if(n[i]=='9')
        {
            a[i+1]=9;
        }
        else
        {
            k--;
        }
    }
    for(int i=1;i<=k;i++)
    {
        cout<<a[i];
    }
    return 0;
}
