#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    string a;
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
        {
            a+=s[i];
        }
    }
 //   a=std int(a)
  //  a=a.sort(a+1,a+3)
    cout<<a;
    return 0;

}
