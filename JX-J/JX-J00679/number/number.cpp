#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string name;
    cin>>name;
    int s=name.size();
    int x=1;
    for(int i=0;i<s;i++)
    {
        if(name[i]>='0'&&name[i]<='9')
        {
            a[x]=(int)name[i]-48;
            x++;
        }
    }
    sort(a+1,a+x);
    for(int i=x-1;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
