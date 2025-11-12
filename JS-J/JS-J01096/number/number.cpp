#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int num[1000010],ln=0,n[10]={};
    getline(cin,s);
    for(int i=0;i<s.size();i++)
        if(s[i]<='9'&&s[i]>='0') num[ln++]=s[i]-'0';
    for(int i=0;i<ln;i++)
        n[num[i]]++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=n[i];j++)
        printf("%d",i);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
