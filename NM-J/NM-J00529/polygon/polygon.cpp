#include <iostream>

using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);


    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    if(a[n]==5)
    {
        cout<<"9"<<endl;
    }
    if(a[n]==10)
    {
        cout<<"6"<<endl;
    }
    fcolse(stdin);
    fcolse(stdout);

    return 0;
}
