#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string s;
int cnt=0,l;
int a[1000050];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            cnt++;
            a[cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--)
    {
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
