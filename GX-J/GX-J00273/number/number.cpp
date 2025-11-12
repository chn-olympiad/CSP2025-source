#include <iostream>
#include <string>
using namespace std;
int main()
{
    freopen(number.in,"r",stdout);
    freopen(number.out,"w",stdout);
    string a="",s;
    cin >> s;
    for (int i=0;i<s.length();i++)
    {
        if(s[i]<='9' && s[i]>='0')
        {
            a+=s[i];
        }
    }
    for(int i=0;i<a.length();i++)
    {
        for(int j=a.length()-1;j>0;j--)
        {
            if(a[j]>a[j-1]){
                int p=a[j];
                a[j]=a[j-1];
                a[j-1]=p;
            }
        }
    }
    for (int i=0;i<=a.length();i++)
    {
        cout << a[i];
    }
    return 0;
}
