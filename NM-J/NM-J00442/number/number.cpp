#include<iostream>
#include<string>
using namespace std;

int b[10000];
int d,e;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a;
    cin>>a;
    for(int i=0;i<=a.size();i++)
    {
    	if(a[i]>='0'&&a[i]<='9')
        {
            b[i]=a[i];
            d++;

        }

    }
    while(b.size())
    {
        int c=b.max();
        for(int i=1;i<=d;i++)
        {
            c*=10;
        }
        d--;
        b-=c;
        e+=c;
    }
    cout<<e;
    return 0;
}
