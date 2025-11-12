#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int i,j,k=0,l=s.size();
    for(i=0;i<l;i++)
        if(s[i]>='0'&&s[i]<='9')
        {
            k++;
            a[k]=int(s[i]-48);
        }
    for(i=k;i>1;i--)
        for(j=1;j<i;j++)
            if(a[j]<=a[j+1])
                swap(a[j],a[j+1]);
    for(i=1;i<=k;i++)
        cout<<a[i];
    return 0;
}
