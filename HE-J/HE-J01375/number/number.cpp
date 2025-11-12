#include <bits/stdc++.h>
using namespace std;
string a,s;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int m=a.size();
    for(int i=0;i<m;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            s+=a[i];
        }
    }
    sort(s.begin(),s.end(),cmp);
    cout<<s;
    return 0;
}
