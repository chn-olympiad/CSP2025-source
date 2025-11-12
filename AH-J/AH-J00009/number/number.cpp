#include<bits/stdc++.h>
using namespace std;
string s;
int b[10];
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
             b[s[i]-'0']++;
     }
    for(int i=9;i>=0;i--)
         for(int j=1;j<=b[i];j++)
               printf("%c",char(i+'0'));
    return 0;
}
