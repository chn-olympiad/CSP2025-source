#include<bits/stdc++.h>
using namespace std;
string s1,s2;
long long a[100005],len=0,c=0,i=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s1;
    len=s1.size();
    for(int j=0;j<len;j++)
    {
        if(s1[j]>='0'&&s1[j]<='9')
        {
            a[j]=s1[j]-'0';
        }
    }

    for(int k=0;k<len;k++)
    {
        for(int m=0;m<len;m++)
        {
            if(a[m]==-2)a[m]==0;
        }
        for(int p=0;p<len-1;p++)
        {
            if(a[p]<a[p+1])swap(a[p],a[p+1]);
        }
    }
    for(int m=0;m<len;m++)
    {
        if(a[m]>0)cout<<a[m];
        if(a[m]==-2)cout<<0;
    }
    return 0;
}
