#include<bits/stdc++.h>
using namespace std;
int b[100];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string a;
    int s=0,q=0;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(48<=a[i] &&  a[i]<=57)
        {
            b[s]=a[i]-'0';
            s++;
        }
    }
    sort(b,b+s);
    for(int i=s-1;i>=0;i--)
    {
        q=q*10+b[i];
    }
    cout<<q;

}
