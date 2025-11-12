#include <iostream>

using namespace std;
int d[2500050];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i=0; i<a; i++)
    {
        cin>>d[i];
    }
    if(a+b==a||a+b==b)
        cout << 1 ;
    else if((a+b)%2==1)
        cout << 2 ;
    else if(a%b==0||b%a==0)
        cout << 2 ;
    else
        cout<<0;
    return 0;
}
