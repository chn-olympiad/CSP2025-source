#include<iostream>
#include<cstring>
using namespace std;
string a;
int b[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int len=a.length();
    for(int i=0;i<len;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            int num=a[i]-'0';
            b[num]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=b[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
