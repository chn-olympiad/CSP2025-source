#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1]=0;
    cin>>s;
    int l=s.size();
    if(l==1)
    {
    cout<<s[0]-'0';
    return 0;
    }
    int j=0;
    for(int i=0;i<l;i++)
    {

        if(s[i]>='0'&&s[i]<='9')
        {

            a[j]=s[i]-'0';
            j++;
        }
        else continue;
    }
    for(int i=0;i<l;i++)
    {

        for(int j=i;j<l;j++)
        {

        if(a[j]>=a[i]) swap(a[i],a[j]);
        }
    }
    for(int i=0;i<l;i++) cout<<a[i];
    return 0;
}
