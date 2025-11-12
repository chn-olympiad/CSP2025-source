#include<iostream>
#include<cstring>
using namespace std;
int b[12]={0};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;cin>>a;
    int len=a.length();
    for(int i=0;i<len;i++)
    {
        int aa=a[i]-48;
        if(aa>=0 && aa<=9)b[aa]++;
    }
    for(int i=9;i>=0;i--)
    {
        while(b[i]!=0)
        {
            cout<<i;b[i]--;
        }
    }
    return 0;
}
