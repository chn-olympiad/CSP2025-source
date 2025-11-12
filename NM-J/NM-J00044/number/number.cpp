#include <iostream>
#include <string>
using namespace std;
int b[10];
int main()
{
    frepone("number.in","r",stdin);
    frepone("number.out","w",stdout);
    string a,b;
    bool c=1;
    cin >> a;
    for(int i=0;i<a.sels();i++)
    {
        if (a[i]>='1' && a[i]<='9')
        {
            int o;
            o=a[i]-'a';
            b[o]++;
        }
    }
    for(int i=9;i=-1;i+=0)
    {
        if(b[i]!=0)cout << i;
        else i-- ;
    }
    return 0;
}
