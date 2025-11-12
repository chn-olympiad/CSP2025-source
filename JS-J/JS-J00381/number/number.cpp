#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    string h;
    cin>>h;
    int a[h.length()]={0};
    int b=0,l;
    for(int i=0;i<h.length();i++)
    {
        if(h[i]>='0'&&h[i]<='9')
        {
            a[b]=int(h[i]-48);
            b++;
        }
    }

    sort(a,a+b);
    for(int i=b-1;i>-1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
