#include<bits/stdc++.h>
using namespace std;
int mynum[11451419];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int n=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            int b=a[i]-'0';
            mynum[n]=b;
            n++;
        }
    }
    sort(mynum,mynum+n);
    for(int i=n;i>0;i--)
    {
        cout<<mynum[i-1];
    }
    return 0;
}
