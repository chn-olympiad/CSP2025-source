#include<bits/stdc++.h>
using namespace std;
string str,newstr;
bool cmp(char a,char b)
{
    return a>b;
}
int main()
{//
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>str;
    for(int i=0;str[i];i++)
    {
        if(!isalpha(str[i]))
        {
            newstr+=str[i];
        }
    }
    sort(newstr.begin(),newstr.end(),cmp);
    cout<<newstr<<endl;
    return 0;
}