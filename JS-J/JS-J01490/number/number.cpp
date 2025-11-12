#include<bits/stdc++.h>
using namespace std;
int a[1000005],k=0;
string s;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[k++]=int(s[i]-'0');
        }
    }
    sort(a,a+k,greater<int>());
    for(int i=0;i<k;i++)
    {
        cout<<a[i];
    }
    return 0;
}