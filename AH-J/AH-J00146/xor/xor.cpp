#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<string> num2;
int cnt a1,a0;

void turn2(int x)
{
    string s="";
    char c;
    if(x==0)
        s="0";
    while(x)
    {
        c=(x%2)+'0';
        s=s+c;
        x/=2;
    }
    num2.push_back(s);
    return;
}

int turn10(string s)
{
    int len=s.size();
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        int x=s[i]-'0';
        cnt=cnt+x*pow(2,i);
    }
    return cnt;
}

string xorr(string s1,string s2)
{
    int len;
    if(s1.size()==s2.size())
        len=s1.size();
    else if(s1.size()<s2.size())
    {
        len=s2.size();
        for(int i=s1.size();i<s2.size();i++)
            s1=s1+'0';
    }
    else
    {
        len=s1.size();
        for(int i=s2.size();i<s1.size();i++)
            s2=s2+'0';
    }

    string s="";
    for(int i=0;i<len;i++)
    {
        if(s1[i]!=s2[i])
            s=s+'1';
        else
            s=s+'0';
    }
    return s;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==1) a1++;
        else if (x==0) a0++;
        turn2(x);
    }
    if(a1+a0==n)
    {
        if(k==1)
        {
            cout<<a1;
            return 0;
        }
        else
        {
            cout<<a0;
            return 0;
        }
    }
    int cnt=0;
    string s=num2[0];
    int l=0,r=0;
    for(int i=1;i<n;i++)
    {
        if(turn10(s)==k)
        {
            cnt++;
            l=r+1;
            r=l;
            s=num2[l];
            continue;
        }
        if(turn10(num2[i])==k)
        {
            l=i+1;
            r=l;
            s=num2[l];
            i=l+1;
        }
        s=xorr(s,num2[i]);
        r++;
        if(i==n-1)
        {
            if(turn10(s)==k)
            {
                cnt++;
                break;
            }
            l++;
            i=l+1;
            r=l;
            s=num2[l];
        }
    }
    cout<<cnt;
    return 0;
}
