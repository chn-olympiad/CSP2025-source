#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,a;
    int max=0,c=0;
    cin >>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&a[i]<='9')
        {
           a[c]=s[i]-'0';
           a++;
        }
    }
    sort(a+0,a+c);
    for(int j=c-1;j>=0;j++)
    {
        max=max*10+a[j];
    }
    cout <<max;
    return 0;
}
