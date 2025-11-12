#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    string anss="";
    int len=s.size();
    for(int i=0;i<len;++i)
    {
        if(s[i]>='0'&&s[i]<='9')
            anss+=s[i];
    }
    sort(anss.begin(),anss.end(),greater<char>());
    cout<<(anss);
    return 0;
}
