#include<bits/stdc++.h>
using namespace std;

string s;
string a[1003],s1;
long long c,ans;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    c=s.size();
    for(int i=0;i<s.size();i++){
        if(int(s[i]-48)>=0 && int(s[i]-48)<=9)
        {
            a[ans]=s[i];
            ans++;
        }
    }
    sort(a,a+ans);
    ans--;
    for(int i=ans;i>=0;i--)
    {
        cout<<a[i];
    }

    return 0;
}
