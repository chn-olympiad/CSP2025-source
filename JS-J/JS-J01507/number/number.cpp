#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
    cin>>s;
    int len=s.size();
    int n=1;
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[n]=s[i]-'0';
            n++;
        }
    }
    n--;
    sort(a+1,a+n+1);
    int sum=0;
    for(int i=n;i>=1;i--)
    {
        sum=sum*10+a[i];
    }
    cout<<sum;

    return 0;
}
