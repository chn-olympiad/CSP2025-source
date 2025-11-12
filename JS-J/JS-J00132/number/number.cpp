#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,str="";
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9')str+=s[i];
    }
    sort(str.begin(),str.end());
    cout<<str;
    return 0;
}
