#include<bits/stdc++.h>
using namespace std;
string s;
string ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
           ans=ans+s[i];
        }
    }
    for(int i=0;i<ans.size()-1;i++)
    {
        if(ans[i]<ans[i+1])
        {
            char a=ans[i+1];
            ans[i+1]=ans[i];
            ans[i]=a;
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }
    return 0;
}
