#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s1;
    cin>>s1;
    int n=s1.size(),cnt=0,s2cd=0;
    string s2;
    for(int i=0;i<n;i++)
    {
        if(s1[i]-'0'<10 && s1[i]-'0'>=1)
        {
            s2[cnt]=s1[i];
            cnt++;
            s2cd++;
        }
    }


    string s3=s2;
    int cct=0;
    for(int j=0;j<s2cd;j++)
    {
        int xb=-1;
        int mx=0;
        int q=0;
        for(int i=0;i<s2cd;i++)
        {
            if(s2[i]-'0'>q)
            {
                q=s2[i]-'0';
                xb++;
            }
            mx=q;
        }
        s2[xb]=0;
        cout<<mx;
    }
    int ppt=0;
    for(int i=0;i<s2cd;i++)
    {
        if(s3[i]-'0'<1) ppt++;
    }
    for(int i=0;i<ppt;i++)
    {
        cout<<'0';
    }

    return 0;
}
