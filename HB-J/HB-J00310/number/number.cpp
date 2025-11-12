#include <bits/stdc++.h>
using namespace std;
int k=1,a[1000006];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","d",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            a[k]=s[i]-'0';
            k++;
        }
    }
    k--;
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--)
    {
        cout <<a[i];
    }
    return 0;
}
