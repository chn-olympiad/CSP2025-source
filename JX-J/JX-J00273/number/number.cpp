#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int cmp(int c,int b)
{
    return c>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int t=0,r;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            r++;

        }
        else
        {
            t++;
            a[t]=s[i];
        }
    }
    sort(a+1,a+t+1,cmp);
    for(int i=1;i<=t;i++)
        cout<<a[i]-48;
    return 0;
}
