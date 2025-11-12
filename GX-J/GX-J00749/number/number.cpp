#include<bits/stdc++.h>
using namespace std;
bool pd(int a,int b)
{
    if(a>b)return 1;
    return 0;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int d=-1,a[1009000];
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            d++;
            a[d]=s[i];
        }
    }
    sort(a,a+d,pd);
    for(int i=0;i<d;i++)
    {
       cout<<a[i]-'0';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
