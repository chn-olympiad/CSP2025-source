#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[511111];
bool bj[111111]={false};
string tt[111111];
string two(int te)
{
    string s,ss;
    while(te!=0)
    {
        char c;
        c=te%2+'0';
        s=s+c;
        te/=2;
    }
    for(int i=s.size()-1;i>=0;i--)
    {
        ss=ss+s[i];
    }
    return ss;
}
string xorr(string two1,string two2)
{
    string two3;
    if(two1.size()!=two2.size())
    {
        if(two1.size()>two2.size())
        {
            int l=two1.size()-two2.size();
            for(int i=1;i<=l;i++)
            {
                two2='0'+two2;
            }
        }
        else
        {
            int l=two2.size()-two1.size();
            for(int i=1;i<=l;i++)
            {
                two1='0'+two1;
            }
        }
    }
    for(int i=0;i<max(two1.size(),two2.size());i++)
    {
        if(two1[i]==two2[i]) two3+='0';
        else two3+='1';
    }
    return two3;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    string sk=two(k);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        tt[i]=two(a[i]);
        if(tt[i]==sk)
        {
            bj[i]=true;
            ans++;
        }
    }
    for(int i=1;i<=n-1;i++)
    {
        if(xorr(tt[i],tt[i+1])==sk&&bj[i]==false&&bj[i+1]==false)
        {
            bj[i]=true;
            bj[i+1]=true;
            ans++;
            i++;
        }
    }
    for(int i=1;i<=n-2;i++)
    {
        if(xorr(xorr(tt[i],tt[i+1]),tt[i+2])==sk&&bj[i]==false&&bj[i+1]==false&&bj[i+2]==false)
        {
            bj[i]=true;
            bj[i+1]=true;
            bj[i+2]=true;
            ans++;
            i+=2;
        }
    }
    for(int i=1;i<=n-3;i++)
    {
        if(xorr(xorr(xorr(tt[i],tt[i+1]),tt[i+2]),tt[i+3])==sk&&bj[i]==false&&bj[i+1]==false&&bj[i+2]==false&&bj[i+3]==false)
        {
            bj[i]=true;
            bj[i+1]=true;
            bj[i+2]=true;
            bj[i+3]=true;
            ans++;
            i+=3;
        }
    }
    for(int i=1;i<=n-4;i++)
    {
        if(xorr(xorr(xorr(xorr(tt[i],tt[i+1]),tt[i+2]),tt[i+3]),tt[i+4])==sk&&bj[i]==false&&bj[i+1]==false&&bj[i+2]==false&&bj[i+3]==false&&bj[i+4]==false)
        {
            bj[i]=true;
            bj[i+1]=true;
            bj[i+2]=true;
            bj[i+3]=true;
            bj[i+4]=true;
            ans++;
            i+=4;
        }
    }
    for(int i=1;i<=n-5;i++)
    {
        if(xorr(xorr(xorr(xorr(xorr(tt[i],tt[i+1]),tt[i+2]),tt[i+3]),tt[i+4]),tt[i+5])==sk&&bj[i]==false&&bj[i+1]==false&&bj[i+2]==false&&bj[i+3]==false&&bj[i+4]==false&&bj[i+5]==false)
        {
            bj[i]=true;
            bj[i+1]=true;
            bj[i+2]=true;
            bj[i+3]=true;
            bj[i+4]=true;
            bj[i+5]=true;
            ans++;
            i+=5;
        }
    }
    for(int i=1;i<=n-6;i++)
    {
        if(xorr(xorr(xorr(xorr(xorr(xorr(tt[i],tt[i+1]),tt[i+2]),tt[i+3]),tt[i+4]),tt[i+5]),tt[i+6])==sk&&bj[i]==false&&bj[i+1]==false&&bj[i+2]==false&&bj[i+3]==false&&bj[i+4]==false&&bj[i+5]==false&&bj[i+6]==false)
        {
            bj[i]=true;
            bj[i+1]=true;
            bj[i+2]=true;
            bj[i+3]=true;
            bj[i+4]=true;
            bj[i+5]=true;
            bj[i+6]=true;
            ans++;
            i+=6;
        }
    }
    for(int i=1;i<=n-7;i++)
    {
        if(xorr(xorr(xorr(xorr(xorr(xorr(xorr(tt[i],tt[i+1]),tt[i+2]),tt[i+3]),tt[i+4]),tt[i+5]),tt[i+6]),tt[i+7])==sk&&bj[i]==false&&bj[i+1]==false&&bj[i+2]==false&&bj[i+3]==false&&bj[i+4]==false&&bj[i+5]==false&&bj[i+6]==false&&bj[i+7]==false)
        {
            bj[i]=true;
            bj[i+1]=true;
            bj[i+2]=true;
            bj[i+3]=true;
            bj[i+4]=true;
            bj[i+5]=true;
            bj[i+6]=true;
            bj[i+7]=true;
            ans++;
            i+=7;
        }
    }
    for(int i=1;i<=n-8;i++)
    {
        if(xorr(xorr(xorr(xorr(xorr(xorr(xorr(xorr(tt[i],tt[i+1]),tt[i+2]),tt[i+3]),tt[i+4]),tt[i+5]),tt[i+6]),tt[i+7]),tt[i+8])==sk&&bj[i]==false&&bj[i+1]==false&&bj[i+2]==false&&bj[i+3]==false&&bj[i+4]==false&&bj[i+5]==false&&bj[i+6]==false&&bj[i+7]==false&&bj[i+8]==false)
        {
            bj[i]=true;
            bj[i+1]=true;
            bj[i+2]=true;
            bj[i+3]=true;
            bj[i+4]=true;
            bj[i+5]=true;
            bj[i+6]=true;
            bj[i+7]=true;
            bj[i+8]=true;
            ans++;
            i+=8;
        }
    }
    for(int i=1;i<=n-9;i++)
    {
        if(xorr(xorr(xorr(xorr(xorr(xorr(xorr(xorr(xorr(tt[i],tt[i+1]),tt[i+2]),tt[i+3]),tt[i+4]),tt[i+5]),tt[i+6]),tt[i+7]),tt[i+8]),tt[i+9])==sk&&bj[i]==false&&bj[i+1]==false&&bj[i+2]==false&&bj[i+3]==false&&bj[i+4]==false&&bj[i+5]==false&&bj[i+6]==false&&bj[i+7]==false&&bj[i+8]==false&&bj[i+9]==false)
        {
            bj[i]=true;
            bj[i+1]=true;
            bj[i+2]=true;
            bj[i+3]=true;
            bj[i+4]=true;
            bj[i+5]=true;
            bj[i+6]=true;
            bj[i+7]=true;
            bj[i+8]=true;
            bj[i+9]=true;
            ans++;
            i+=9;
        }
    }
    for(int i=1;i<=n-10;i++)
    {
        if(xorr(xorr(xorr(xorr(xorr(xorr(xorr(xorr(xorr(xorr(tt[i],tt[i+1]),tt[i+2]),tt[i+3]),tt[i+4]),tt[i+5]),tt[i+6]),tt[i+7]),tt[i+8]),tt[i+9]),tt[i+10])==sk&&bj[i]==false&&bj[i+1]==false&&bj[i+2]==false&&bj[i+3]==false&&bj[i+4]==false&&bj[i+5]==false&&bj[i+6]==false&&bj[i+7]==false&&bj[i+8]==false&&bj[i+9]==false&&bj[i+10]==false)
        {
            bj[i]=true;
            bj[i+1]=true;
            bj[i+2]=true;
            bj[i+3]=true;
            bj[i+4]=true;
            bj[i+5]=true;
            bj[i+6]=true;
            bj[i+7]=true;
            bj[i+8]=true;
            bj[i+9]=true;
            bj[i+10]=true;
            ans++;
            i+=10;
        }
    }
    cout<<ans<<endl;
    return 0;
}
