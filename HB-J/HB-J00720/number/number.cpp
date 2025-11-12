#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000005],j;
bool cmp(int n1,int n2)
{
    return n1>n2;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<='9'&&a[i]>='0')
        {
            b[j++]=a[i]-'0';
        }
    }
    sort(b,b+j-1,cmp);
    for(int i=0;i<j;i++)
    {
        cout<<b[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
