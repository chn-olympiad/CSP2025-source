#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],indx=0;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            indx++;
            a[indx]=s[i]-'0';
        }
    }
    sort(a+1,a+1+indx,cmp);
    for(int i=1;i<=indx;i++)
    {
        cout<<a[i];
    }
	return 0;
}
