#include <iostream>
#include <cstring>
using namespace std;
const int N=1e6+5;
int a[N];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    getline(cin,n);
    int ans=0;
    for(int i=0;i<n.size();i++)
    {
        if(n[i]<='9'&&n[i]>='0')
        {
            a[i]=int(n[i]-48);
            if(n[i]=='0')
            {
                ans++;
            }
        }
    }
    for(int i=0;i<n.size();i++)
    {
        for(int j=0;j<n.size();j++)
        {
            if(a[j]>=a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=n.size();i>0;i--)
    {
        if(a[i]==0)
        {
            ans--;
        }
        if(ans>=0)
        {
            cout << a[i];
        }
        else if(ans==-1&&a[i]==0)
        {
            continue;
        }
    }
}
