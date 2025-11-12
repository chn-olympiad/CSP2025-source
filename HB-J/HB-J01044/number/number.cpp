#include<bits/stdc++.h>
using namespace std;
bool c(int x,int y)
{
    return x>y;
}
int b[1000000];
int main()
{
    string a;
    cin>>a;
    int n=a.length();
    int bi=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]-'0'>=0&&a[i]-'0'<=9)
        {
            b[bi]=a[i]-'0';
            bi++;
        }
    }
    sort(b,b+bi,c);
    for(int i=0;i<bi;++i)
    {
        cout<<b[i];
    }
    return 0;
}
