#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int a[N];
int cmp(int x,int y)
{

    return x>=y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int tot=0;
   cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')a[++tot]=s[i]-'0';
    }
    sort(a+1,a+tot+1,cmp);
    for(int i=1;i<=tot;i++)
       printf("%d",a[i]);
    return 0;
}
