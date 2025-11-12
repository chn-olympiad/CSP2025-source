#include <bits/stdc++.h>

using namespace std;
int a,c,ans,d0,d1,d2,d3,d4,d5,d6,d7,d8,d9;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(s[i]=='0')
                d0++;
            else if(s[i]=='1')
                d1++;
            else if(s[i]=='2')
                d2++;
            else if(s[i]=='3')
                d3++;
            else if(s[i]=='4')
                d4++;
            else if(s[i]=='5')
                d5++;
            else if(s[i]=='6')
                d6++;
            else if(s[i]=='7')
                d7++;
            else if(s[i]=='8')
                d8++;
            else
                d9++;
        }
    }
    for(int i=0;i<d9;i++)
        cout<<"9";
    for(int i=0;i<d8;i++)
        cout<<"8";
    for(int i=0;i<d7;i++)
        cout<<"7";
    for(int i=0;i<d6;i++)
        cout<<"6";
    for(int i=0;i<d5;i++)
        cout<<"5";
    for(int i=0;i<d4;i++)
        cout<<"4";
    for(int i=0;i<d3;i++)
        cout<<"3";
    for(int i=0;i<d2;i++)
        cout<<"2";
    for(int i=0;i<d1;i++)
        cout<<"1";
    for(int i=0;i<d0;i++)
        cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
