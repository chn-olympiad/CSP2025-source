#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],t;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);


    cin>>s;
    for(int i=0;s[i]!='\0';++i)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i]-'0';
            t++;
        }
    }
    sort(a,a+t+1);
    for(int i=t;i>0;--i)
    {
        cout<<a[i];
    }
    return 0;


    fclose(stdin);
    fclose(stdout);
}
