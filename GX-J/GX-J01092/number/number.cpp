#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005]={0};
bool kp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int j=0;
    for(int i=0;i < s.size();i++)
    {
        if(s[i] >= '0'&&s[i] <= '9')
        {
            j++;
            a[j]=s[i]-'0';
        }
    }
    sort(a+1,a+1+j,kp);
    for(int i=1;i <= j;i++)
    {
        cout<<a[i];
    }
    return 0;
}
