#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
char b[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i = 0;
    cin>>s;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i] <= '9')
        {
            a[i] = s[i];
        }
    }
    for(int i = 0;i<s.size();i++)
    {
        cout<<a[i];

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
