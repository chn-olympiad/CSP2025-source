#include<bits/stdc++.h>

using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int  i=1,n=0,m[10]={};
	string a;
	cin>>a;
    while(i)
    {
        if(a[n]>='0'&&a[n]<='9')
        {
            m[int(a[n])-48]++;
        }
        if(a[n]<'a'||a[n]>'z')
           {
               if(a[n]>'9'||a[n]<'0')
           {


                i--;
            }
           }
           n++;
    }
    for(int i=9;i>=0;i--)
    {
        for(int l=1;l<=m[i];l++)
        {
            cout<<i;
        }
    }
	return 0;
}
