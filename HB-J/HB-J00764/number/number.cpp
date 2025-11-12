#include<bits/stdc++.h>
using namespace std;
string a;
char c[10000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int b=a.length(),m=1;
    for(int i=0;i<b;i++)
    {
        if(a[i]-'0'>=0&&a[i]-'0'<=9)
        {
            c[m]=a[i];
            m++;
        }
    }
    sort(c,c+m);
    for(int i=b;i>=1;i--)
    {
		if(c[i]-'0'>=0&&c[i]-'0'<=9)
		{
			cout<<c[i]-'0';
		}
		
	}
}
