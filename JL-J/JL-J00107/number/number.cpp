#include<iostream>
using namespace std;
string s;
int a[1005],cnt=0,c;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            cnt++;
            a[cnt]=s[i]-48;
        }
    }
    for(int i=0;i<=cnt;i++)
    {
        for(int j=0;j<=cnt;j++)
        {
            if(a[j]<a[i])
            {
                c=a[j];
                a[j]=a[i];
                a[i]=c;
            }
        }
    }
    for(int i=0;i<cnt;i++)
        cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
