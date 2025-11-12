#include <bits/stdc++.h>
using namespace std;
//const int DATA=xx;
/*
char vis[DATA]={};
dfs()
{
    if()
    {
    }
    else
    {
        vis[i]=1;
        dfs()
        vis[i]=0;
    }
    return;
}
*/
/*
struct xxx{

};
xxx ecm[DATA]={};
*/
/*
xx P()
{
    return xx;
}
*/
int ecm[10]={};//jishu
string put_in;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>put_in;
    int max_number=INT_MIN;
    for(int i=0;i<put_in.length();i++)
    {
        if(isdigit(put_in[i]))
        {
            ecm[put_in[i]-'0']++;
            max_number=max(max_number,put_in[i]-'0');
        }
    }
    for(int i=max_number;i>=0;i--)
    {
        if(max_number==0)
        {
            putchar('0');
            return 0;
        }
        for(int j=0;j<ecm[i];j++)
        {
            putchar(i+'0');
        }
    }
    return 0;
}