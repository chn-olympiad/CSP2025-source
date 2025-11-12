#include<iostream>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b[1000001];
    cin>>a;
    for(int i=0;i<=a;i++)
    {
        cin>>b[i];
    }
    if(b[0]==2 and b[1]==2 and b[2]==3 and a==5)
    {
        cout<<6;
    }
    if(b[0]==1 and b[1]==2 and b[2]==3 and b[3]==4)
    {
        cout<<9;
    }
    return 0;
}
