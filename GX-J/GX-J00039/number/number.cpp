#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int z;
    cin>>s;
    z=s.size();
    int a[z+1];
    long long ans=0;
    for(int i=0;i<=z;i++) a[i]=0;
    if(z==1)
    {
        cout<<int(s[0])-48;
        return 0;
    }

    int t=0;
    for(int i=0;i<z;i++)
    {
        if(s[i]<='9' and s[i]>='0')
        {
            t++;
            a[t]=int(s[i])-48;
        }
    }
    sort(a+1,a+t+1);
    for(int i=t;i>0;i--)
        cout<<a[i];
    return 0;
}
