#include<iostream>
using namespace std;
int main()
{
    int a,b,x=0,y=0;
    cin>>a>>b;
    int w,c=0;
    cin>>w;
    int l;
    for(int i=1;i<a*b;i++)
    {
        cin>>l;
        if(l>w)
        {
            c++;
        }
    }
    if(c%(2*a)>=a)
    {
        x=a-(c%(2*a)-a);
    }
    else
    {
        x=c%a+1;
    }
    y+=c/a+1;
    cout<<y<<' '<<x;
    return 0;
}
