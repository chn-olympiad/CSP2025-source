#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[1000001];
    int a[1000001];
    cin.getline(s,1000001);
    int n=strlen(s);
    for(int i=0;i<=1000001;i++)
    {
        if(s[i+1]>='0' && s[i+1]<='9')swap(s[i],s[i+1]);
        if(s[i]>='a' && s[i]<='z')s[i]=' ';
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(s[i]=='0' && s[i+j]=='1')swap(s[i],s[i+j]);
            if(s[i]=='0' && s[i+j]=='2')swap(s[i],s[i+j]);
            if(s[i]=='0' && s[i+j]=='3')swap(s[i],s[i+j]);
            if(s[i]=='0' && s[i+j]=='4')swap(s[i],s[i+j]);
            if(s[i]=='0' && s[i+j]=='5')swap(s[i],s[i+j]);
            if(s[i]=='0' && s[i+j]=='6')swap(s[i],s[i+j]);
            if(s[i]=='0' && s[i+j]=='7')swap(s[i],s[i+j]);
            if(s[i]=='0' && s[i+j]=='8')swap(s[i],s[i+j]);
            if(s[i]=='0' && s[i+j]=='9')swap(s[i],s[i+j]);
            if(s[i]=='1' && s[i+j]=='2')swap(s[i],s[i+j]);
            if(s[i]=='1' && s[i+j]=='3')swap(s[i],s[i+j]);
            if(s[i]=='1' && s[i+j]=='4')swap(s[i],s[i+j]);
            if(s[i]=='1' && s[i+j]=='5')swap(s[i],s[i+j]);
            if(s[i]=='1' && s[i+j]=='6')swap(s[i],s[i+j]);
            if(s[i]=='1' && s[i+j]=='7')swap(s[i],s[i+j]);
            if(s[i]=='1' && s[i+j]=='8')swap(s[i],s[i+j]);
            if(s[i]=='1' && s[i+j]=='9')swap(s[i],s[i+j]);
            if(s[i]=='2' && s[i+j]=='3')swap(s[i],s[i+j]);
            if(s[i]=='2' && s[i+j]=='4')swap(s[i],s[i+j]);
            if(s[i]=='2' && s[i+j]=='5')swap(s[i],s[i+j]);
            if(s[i]=='2' && s[i+j]=='6')swap(s[i],s[i+j]);
            if(s[i]=='2' && s[i+j]=='7')swap(s[i],s[i+j]);
            if(s[i]=='2' && s[i+j]=='8')swap(s[i],s[i+j]);
            if(s[i]=='2' && s[i+j]=='9')swap(s[i],s[i+j]);
            if(s[i]=='3' && s[i+j]=='4')swap(s[i],s[i+j]);
            if(s[i]=='3' && s[i+j]=='5')swap(s[i],s[i+j]);
            if(s[i]=='3' && s[i+j]=='6')swap(s[i],s[i+j]);
            if(s[i]=='3' && s[i+j]=='7')swap(s[i],s[i+j]);
            if(s[i]=='3' && s[i+j]=='8')swap(s[i],s[i+j]);
            if(s[i]=='3' && s[i+j]=='9')swap(s[i],s[i+j]);
            if(s[i]=='4' && s[i+j]=='5')swap(s[i],s[i+j]);
            if(s[i]=='4' && s[i+j]=='6')swap(s[i],s[i+j]);
            if(s[i]=='4' && s[i+j]=='7')swap(s[i],s[i+j]);
            if(s[i]=='4' && s[i+j]=='8')swap(s[i],s[i+j]);
            if(s[i]=='4' && s[i+j]=='9')swap(s[i],s[i+j]);
            if(s[i]=='5' && s[i+j]=='6')swap(s[i],s[i+j]);
            if(s[i]=='5' && s[i+j]=='7')swap(s[i],s[i+j]);
            if(s[i]=='5' && s[i+j]=='8')swap(s[i],s[i+j]);
            if(s[i]=='5' && s[i+j]=='9')swap(s[i],s[i+j]);
            if(s[i]=='6' && s[i+j]=='7')swap(s[i],s[i+j]);
            if(s[i]=='6' && s[i+j]=='8')swap(s[i],s[i+j]);
            if(s[i]=='6' && s[i+j]=='9')swap(s[i],s[i+j]);
            if(s[i]=='7' && s[i+j]=='8')swap(s[i],s[i+j]);
            if(s[i]=='7' && s[i+j]=='9')swap(s[i],s[i+j]);
            if(s[i]=='8' && s[i+j]=='9')swap(s[i],s[i+j]);
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(s[i]!=' ')cout<<s[i];
    }
}
