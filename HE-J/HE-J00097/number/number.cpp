#include<bits/stdc++.h>
using namespace std;
long long b[1000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int shu=0;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='1')b[++shu]=1;
        if(a[i]=='2')b[++shu]=2;
        if(a[i]=='3')b[++shu]=3;
        if(a[i]=='4')b[++shu]=4;
        if(a[i]=='5')b[++shu]=5;
        if(a[i]=='6')b[++shu]=6;
        if(a[i]=='7')b[++shu]=7;
        if(a[i]=='8')b[++shu]=8;
        if(a[i]=='9')b[++shu]=9;
        if(a[i]=='0')b[++shu]=-1;

    }
    sort(b+0,b+shu);
    for(int i=shu-1;i>=0;i--)
    {
        if(b[i]==-1)
        {
           cout<<0;
        }
        else
        cout<<b[i];
    }
}
