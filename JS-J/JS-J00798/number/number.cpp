#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=0;
    int a[1000001];
    for(int i=0;i<s.length();i++)
    {
        int zhi=s[i]-'0';
        if(zhi>=0&&zhi<=9)
        {
            n++;
            a[n]=zhi;
        }
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--) cout<<a[i];
    return 0;
}
