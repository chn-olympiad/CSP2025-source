#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b[a.size()+1]={};
    int j=1;
    for(int i=0;i<a.size();i++)
    {
        if('0'<=a[i]&&a[i]<='9')
        {
            b[j]=a[i]-48;
            j+=1;
        }
    }
    sort(b+1,b+j);
    for(int i=j-1;i>0;i--)
    {
        cout<<b[i];
    }
    return 0;
}
