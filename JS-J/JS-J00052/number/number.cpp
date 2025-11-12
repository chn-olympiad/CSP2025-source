#include <bits/stdc++.h>
using namespace std;
string str,str1;
int l;
char ch1,ch2;
int a[1000005];
void st(int n)
{
    for(int i = 0 ; i < n; i++)
    {
        for(int j = i ; j < n; j++)
        {
            if(a[i] < a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i = 0 ; i < l;i++) cout<<a[i];
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i = 0; i < str.length();i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            ch1 = str[i];
            str1 +=str[i];
        }
    }
    l = str1.length();
    for(int i = 0 ; i < str1.length();i++)
    {
        a[i] = str1[i] - 48;
    }
    st(l);
    return 0;
}
