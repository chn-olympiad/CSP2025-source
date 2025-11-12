#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long a[1000001],k=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            k++;
            a[k]=s[i]-'0';
        }
    }
    for(int i=1;i<=k-1;i++)
    {

        for(int j=i;j<=k-1;j++)
        {
	    if(a[j]<a[j+1])
	    {
               int o=a[j+1];
               a[j+1]=a[j];
               a[j]=o;
	    }
        }
    }
    for(int i=1;i<=k;i++)
    {

        cout<<a[i];
    }
    return 0;
}
