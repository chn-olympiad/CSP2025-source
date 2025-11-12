#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[20];
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    for(int i=0;i<n.size();i++)
    {
        if(n[i]<'a')
        {
            a[n[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        if(a[i]>0)
        {
            for(int j=1;j<=a[i];j++)
            {
                cout<<i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
