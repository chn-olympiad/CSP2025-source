#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int [1000000];
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[b]=s[i]-'0';
            b++;
        }
    }
    sort(a,a+b);
    for(int i=0;i<b;i++)
    cout<<a[i];
    return 0;
}
