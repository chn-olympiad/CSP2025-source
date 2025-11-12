#include<bits/stdc++.h>
using namespace std;
int cnt[10]={0};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,s1="";
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')    cnt[s[i]-'0']++;
    for(int i=9;i>=0;i--)
    {
        if(cnt[i]!=0)
        {
            if(i==9)
                while(cnt[i]--)
                    s1+="9";
            if(i==8)
                while(cnt[i]--)
                    s1+="8";
            if(i==7)
                while(cnt[i]--)
                    s1+="7";
            if(i==6)
                while(cnt[i]--)
                    s1+="6";
            if(i==5)
                while(cnt[i]--)
                    s1+="5";
            if(i==4)
                while(cnt[i]--)
                    s1+="4";
            if(i==3)
                while(cnt[i]--)
                    s1+="3";
            if(i==2)
                while(cnt[i]--)
                    s1+="2";
            if(i==1)
                while(cnt[i]--)
                    s1+="1";
            if(i==0)
                while(cnt[i]--)
                    s1+="0";
        }
    }
    cout<<s1;
    return 0;
}
//#Shang4Shan3Ruo6Shui4
