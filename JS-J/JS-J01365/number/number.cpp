#include <bits/stdc++.h>
using namespace std;
string s;
int num[1000005],p;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            p++;
            num[p]=s[i]-'0';
        }
    }
    sort(num+1,num+p+1);
    for(int i=p;i>=1;i--) cout<<num[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
