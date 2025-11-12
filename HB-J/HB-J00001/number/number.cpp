#include <bits/stdc++.h>
using namespace std;
int qw[1000001],we[1000001],er[1000001];
int main()
{
    freopen("nember.in","r",stdin);
    freopen("nember.out","r",stdout);
    string s1;
    cin>>s1;
    int a=s1.length();
    for(int i=1;i<=a;i++)
    {
        qw[i]=s1[i]-'0';
    }
    int s=0;
    for(int i=1;i<=a;i++)
    {
        if(0<=qw[i]&&qw[i]<=9)
        {
            s++;
            we[s]==qw[i];
        }
    }
    int f;
    for(int i=1;i<=s;i++)
    {
        int q=-1;
        if(we[i]>=q)
        {
            q=we[i];
            f=i;
        }
        er[i]=qw[f];
        qw[f]=0;
    }
    for(int i=1;i<=s;i++)
    {
        printf("%d",er[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
