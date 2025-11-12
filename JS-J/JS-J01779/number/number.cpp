#include<iostream>
#include<algorithm>
using namespace std;
bool bj(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    string s;
    int a[1000006];
    int n=1;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[n]=s[i]-48;
            n++;
        }
    }
    sort(a+1,a+n,bj);
    for(int i=1;i<n;i++)
        cout<<a[i];
    cout<<'\n';
    return 0;
}
