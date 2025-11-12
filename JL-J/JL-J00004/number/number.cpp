#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,a[10000000],b;
bool cmp(int i,int j)
{
    return i>j;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    if(s.size()==1)
    {
        cout<<s[0];
        return 0;
    }
    for(int i=0;i<s.size();i++)
    {

        if(s[i]<='9' && s[i]>='0')
        {
            a[b]=s[i]-'0';
            b++;
        }

    }
    sort(a,a+b,cmp);
    for(int i=0;i<b;i++)
        cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
