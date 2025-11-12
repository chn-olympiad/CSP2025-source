#include<bits/stdc++.h>
using namespace std;
int num[1010];
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int j=1;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]<=57&&s[i]>=47)
        {
            num[j]=s[i]-'0';
            j++;
        }
    }
    sort(num+1,num+j,cmp);
    for(int i=1;i<j;i++)
    {
        cout<<num[i];
    }
    return 0;
}
