#include<bits/stdc++.h>
using namespace std;
int a[1000001];
char b[1000001];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int c=0,d=1;
    while(cin>>b[d])
    {
        d++;
    }
    for(int i=1;i<=d;i++)
    {
        if(b[i]=='9')
        {
            a[c]=9;
            c++;
        }
        if(b[i]=='8')
        {
            a[c]=8;
            c++;
        }if(b[i]=='7')
        {
            a[c]=7;
            c++;
        }if(b[i]=='6')
        {
            a[c]=6;
            c++;
        }if(b[i]=='5')
        {
            a[c]=5;
            c++;
        }if(b[i]=='4')
        {
            a[c]=4;
            c++;
        }if(b[i]=='3')
        {
            a[c]=3;
            c++;
        }if(b[i]=='2')
        {
            a[c]=2;
            c++;
        }if(b[i]=='1')
        {
            a[c]=1;
            c++;
        }if(b[i]=='0')
        {
            a[c]=0;
            c++;
        }
    }
    sort(a,a+c+1,cmp);
    for(int j=0;j<c;j++)
    {
        cout<<a[j];
    }

    return 0;
}
