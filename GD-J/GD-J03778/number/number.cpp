#include <iostream>
#include <string>
using namespace std;
int awa[10];
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int l = a.length();

    for(int i = 0;i<=l-1;i++)
    {
        if(a[i]>=0||a[i]<=9)
        {
            int m =a[i]-48;
            awa[m]++;

        }

    }
    for(int i = 9;i>=0;i--)
    {

        for(int j = 1;j<= awa[i];j++)
        {
            cout<<i;


        }
    }


}
