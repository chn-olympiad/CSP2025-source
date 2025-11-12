#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int n[10];
    for(int i=0;i<=9;i++)
    {
        n[i]=0;
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            n[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=n[i];j++)
        {
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
