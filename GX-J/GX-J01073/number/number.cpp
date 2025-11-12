#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[123456]={0};
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            a[i]=s[i]-'0';
        else
            a[i]=10;
    }
    for(int i=0;i<s.size()-1;i++)
    {
        for(int j=0;j<s.size()-i;j++)
        {
                if(a[j]<a[j+1])
                    swap(a[j],a[j+1]);
        }
    }
    for(int i=0;i<s.size();i++)
        if(a[i]<10)
           cout<<a[i];
    return 0;
}
