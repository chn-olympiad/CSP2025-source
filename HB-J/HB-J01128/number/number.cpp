#include<bits/stdc++.h>
using namespace std;
int b[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int f=s.size();
    char a[f];
    for(int i=0;i<f;i++)a[i]=s[i];
    for(int i=0;i<f;i++)
    {
        if(a[i]=='0')b[0]++;
        if(a[i]=='1')b[1]++;
        if(a[i]=='2')b[2]++;
        if(a[i]=='3')b[3]++;
        if(a[i]=='4')b[4]++;
        if(a[i]=='5')b[5]++;
        if(a[i]=='6')b[6]++;
        if(a[i]=='7')b[7]++;
        if(a[i]=='8')b[8]++;
        if(a[i]=='9')b[9]++;
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=b[i];j>0;j--)cout<<i;
    }
    return 0;
}
