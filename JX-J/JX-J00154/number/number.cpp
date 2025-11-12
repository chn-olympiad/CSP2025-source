#include<cstdio>
#include<algorithm>
#include<string>
std::string s,ans;
int cnt0,cnt1,cnt2,cnt3,cnt4,cnt5,cnt6,cnt7,cnt8,cnt9;
inline std::string read()
{
    char ch=getchar();std::string str="";
    while((!(ch>='a'&&ch<='z'))&&(!(ch>='0'&&ch<='9')))ch=getchar();
    while((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))str+=ch,ch=getchar();
    return str;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    s=read();
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0') cnt0++;
        if(s[i]=='1') cnt1++;
        if(s[i]=='2') cnt2++;
        if(s[i]=='3') cnt3++;
        if(s[i]=='4') cnt4++;
        if(s[i]=='5') cnt5++;
        if(s[i]=='6') cnt6++;
        if(s[i]=='7') cnt7++;
        if(s[i]=='8') cnt8++;
        if(s[i]=='9') cnt9++;
    }
    for(int i=1;i<=cnt9;i++) putchar('9');
    for(int i=1;i<=cnt8;i++) putchar('8');
    for(int i=1;i<=cnt7;i++) putchar('7');
    for(int i=1;i<=cnt6;i++) putchar('6');
    for(int i=1;i<=cnt5;i++) putchar('5');
    for(int i=1;i<=cnt4;i++) putchar('4');
    for(int i=1;i<=cnt3;i++) putchar('3');
    for(int i=1;i<=cnt2;i++) putchar('2');
    for(int i=1;i<=cnt1;i++) putchar('1');
    for(int i=1;i<=cnt0;i++) putchar('0');
    return 0;
}