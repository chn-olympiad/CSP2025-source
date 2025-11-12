#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    string lin="";
    string yi="";
    string er="";
    string san="";
    string si="";
    string wu="";
    string liu="";
    string qi="";
    string ba="";
    string jiu="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            lin= lin+'0';
        }
        if(s[i]=='1')
        {
            yi=yi+'1';
        }
        if(s[i]=='2')
        {
            er= er+'2';
        }
        if(s[i]=='3')
        {
            san= san+'3';
        }
        if(s[i]=='4')
        {
            si= si+'4';
        }
        if(s[i]=='5')
        {
            wu= wu+'5';
        }
        if(s[i]=='6')
        {
            liu= liu+'6';
        }
        if(s[i]=='7')
        {
            qi= qi+'7';
        }
        if(s[i]=='8')
        {
            ba= ba+'8';
        }
        if(s[i]=='9')
        {
            jiu= jiu+'9';
        }
    }
    cout<<jiu<<ba<<qi<<liu<<wu<<si<<san<<er<<yi<<lin;
    return 0;
}
