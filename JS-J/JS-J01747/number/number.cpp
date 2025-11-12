#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int b[100005],n=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(isdigit(s[i]))
        {
            n++;
            b[n]=int(s[i]-48);
        }
    }
    sort(b+1,b+n+1);
    if(b[n]!=0)
        for(int i=n; i>0; i--)
        {
            cout<<b[i];
        }
    else
        cout<<"0";
    return 0;
}
