#include <iostream>
#include <cstdlib>
using namespace std;
int number[10]={0};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,s1="";
    int i,j;
    cin>>s;
    for(i=0;i<s.length();i++)
        if(s[i]>='0'&&s[i]<='9')
            s1+=s[i];
    for(i=0;i<s1.length();i++)
        number[s1[i]-'0']++;
    for(i=9;i>=0;i--)
    {
        j=number[i];
        while(j--)
            cout<<i;
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
