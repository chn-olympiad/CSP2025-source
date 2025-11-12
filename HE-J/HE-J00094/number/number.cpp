#include<bits/stdc++.h>
using namespace std;
string s1;
float s[1000001];
long long ssize=0;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s1;
    long long l=s1.size();
    for(long long i=0; i<=l; i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
        {
            s[ssize]=s1[i]-'0';
            ssize++;
        }
    }
    sort(s,s+ssize,cmp);
    for(int i=0; i<ssize; i++)
    {
        cout<<s[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
