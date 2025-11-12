#include<bits/stdc++.h>
using namespace std;
string s;
char t[100000000];
int num[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        t[i]=s[i];
        if(t[i]=='0')  num[0]++;
        if(t[i]=='1')  num[1]++;
        if(t[i]=='2')  num[2]++;
        if(t[i]=='3')  num[3]++;
        if(t[i]=='4')  num[4]++;
        if(t[i]=='5')  num[5]++;
        if(t[i]=='6')  num[6]++;
        if(t[i]=='7')  num[7]++;
        if(t[i]=='8')  num[8]++;
        if(t[i]=='9')  num[9]++;
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=0;j<num[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
