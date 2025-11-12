#include <bits/stdc++.h>
using namespace std;
char a[1000001];
char s[1000001];
bool cmp(const int a,const int b)
{
    return a>=b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int t=0;
    for(int i=0;i<100000;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
			a[++t]=s[i];
		}
    }
    sort(a+1 ,a+t+1,cmp);
    for(int i=1;i<=t;i++) cout<<a[i];
    return 0;
}
