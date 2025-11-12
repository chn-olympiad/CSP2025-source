#include<bits/stdc++.h>
using namespace std;
int a[1100000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int k=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if('0'<=s[i] && s[i]<='9')
        {
            k++;
            a[k]=s[i]-'0';
        }
    }
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--)
    {
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
