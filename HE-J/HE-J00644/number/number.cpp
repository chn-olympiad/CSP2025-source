#include<bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int t = s.size();
    for (int i = 0;i<t;++i)
    {
        if (s[i]>=48 && s[i]<=57)
        {
            int n = s[i]-48;
            a[n]++;
        }
    }
    for (int i = 9;i>=0;--i)
    {
        if (a[i] != 0)
        {
            while(a[i]--)
            {
                cout<<i;
            }
        }
    }
	fclose(stdin);
	fclose(stdout);
    return 0;
}
