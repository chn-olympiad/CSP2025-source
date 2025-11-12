#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int i,j=1,a[1000010],l=0;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]-48>=0&&s[i]-48<=9)
        {
            a[j]=s[i]-'0';
            j++;
            l++;
        }
    }
    sort(a+1,a+1+l);
    for(i=l;i>0;i--)
    {
        cout<<a[i];
    }
    return 0;
}
