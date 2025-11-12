#include<bits/stdc++.h>
using namespace std;
int a[1000003]={0};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int b=0,c,i,j=0;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[j]=s[i]-48;
            j++;
        }
    }
    sort(a,a+j);
    for(i=j-1;i>=0;i--)
    {
        cout<<a[i];
    }

    return 0;
}
