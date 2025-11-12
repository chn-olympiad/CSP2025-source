#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1001000]={0},k=0,b=-1,m[10]={0};
    cin >> s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]<='9' && s[i]>='0')
        {
            a[k]=int(s[i])-48;
            k++;
        }
    }
    for(int i=0;i<k;i++)
    {
        m[a[i]]++;
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=0;j<m[i];j++)
        {
            cout << i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
