#include<bits/stdc++.h>
using namespace std;
string s;
int j,t[1000001]={};
long long n;
bool b(int i,int j)
{
    return i>j;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int i=1;
    for(auto a:s)
    {
        if(a>='0'&&a<='9')
        {
            t[i]=(int)a-'0';
            i++;
        }
    }
    sort(t,t+i,b);
    sort(t,t+i,b);
    j=i;
    for(i=0; i<=j-2; i++)
    {
        cout<<t[i];
    }
    return 0;
}
