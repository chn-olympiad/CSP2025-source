#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[10000]={0};
    int k=s.size();
    for(int i=0;i<s.size()-1;i++)
    {
        for(int j=0;j<s.size()-1;j++)
        {
            if(s[j]<s[j+1])
            {
                swap(s[j],s[j+1]);
            }
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' and s[i]<='9')
        {
            cout<<s[i];
        }
    }

    return 0;
}
