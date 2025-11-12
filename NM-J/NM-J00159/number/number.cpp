#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int slen=s.size()+1;
    char a[slen];
    int temp=0;
    for(int i=0;i<slen;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[temp]=s[i];
            temp++;
        }
    }
    int temp1=0;
    for(int k=0;k<temp;k++)
    {
        for(int h=0;h<temp;h++)
        {
            if(a[h]<a[h+1])
            {
                temp1=a[h];
                a[h]=a[h+1];
                a[h+1]=temp1;
            }
        }
    }
    for(int j=0;j<temp;j++)
    {
        cout <<a[j];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}