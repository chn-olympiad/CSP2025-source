#include<bits/stdc++.h>
#define E 10010
using namespace std;
string s1;
int a[E],j=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s1;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]-'0'>=0&&s1[i]-'0'<=9)
        {
            a[j]=s1[i]-'0';
            j++;
        }
    }
    sort(a,a+j);
    for(int i=j-1;i>=0;i--)
        cout<<a[i];
    return 0;
}
